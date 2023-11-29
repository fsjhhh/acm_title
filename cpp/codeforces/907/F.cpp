#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <iomanip> // std::fixed std::setprecision(x) 保留x位小数
#include <array>
#include <bitset>
#include <functional>
#include <ranges>
//#include <bits/stdc++.h>
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

#define int long long

const int N = 5e5 + 10;
struct Point {
    int op, x, val;
} point[N];
struct Node {
    int l, r;
    int sum, tag;
} tr[N * 4];
int n, idx;
int L[N], R[N], num;
std::vector<std::vector<int>> edges(N);

void init(int n) {
    for (int i = 0; i <= 4 * n; i++) {
        tr[i].l = tr[i].r = tr[i].sum = tr[i].tag = 0;
    }
    for (int i = 0; i <= n; i++) {
        point[i].op = point[i].x = point[i].val = 0;
        L[i] = R[i] = 0;
        edges[i].clear();
    }
    idx = 1;
    num = 0;
}

void push_up(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u].l = tr[u].r = l;
        tr[u].sum = tr[u].tag = 0;
        return ;
    }
    tr[u].l = l;
    tr[u].r = r;
    tr[u].tag = 0;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void push_down(int u) {
    if (tr[u].tag == 0) {
        return ;
    }
    tr[u << 1].sum += tr[u].tag * (tr[u << 1].r - tr[u << 1].l + 1ll);
    tr[u << 1].tag += tr[u].tag;
    tr[u << 1 | 1].sum += tr[u].tag * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1ll);
    tr[u << 1 | 1].tag += tr[u].tag;
    tr[u].tag = 0;
}

void modify(int u, int l, int r, int val) {
    if (l <= tr[u].l && r >= tr[u].r) {
        if (val == -INFL) {
            tr[u].sum = 0;
            tr[u].tag = 0;
        } else {
            tr[u].sum += val * (tr[u].r - tr[u].l + 1ll);
            tr[u].tag += val;
        }
        return ;
    }
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) {
        modify(u << 1, l, r, val);
    }
    if (r > mid) {
        modify(u << 1 | 1, l, r, val);
    }
    push_up(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) {
        return tr[u].sum;
    }
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1, res = 0;
    if (l <= mid) {
        res += query(u << 1, l, r);
    } 
    if (r > mid) {
        res += query(u << 1 | 1, l, r);
    }
    push_up(u);
    return res;
}

void solve() {
    std::cin >> n;
    init(n);
    for (int i = 1; i <= n; i++) {
        int op, x;
        std::cin >> op >> x;
        if (op == 1) {
            ++ idx;
            point[i].op = op;
            point[i].x = idx;
            point[i].val = -INFL;
            edges[x].push_back(idx);
            edges[idx].push_back(x);
        } else {
            int val;
            std::cin >> val;
            point[i].op = op;
            point[i].x = x;
            point[i].val = val;
        }
    }

    auto dfs = [&](auto self, int u, int fa) -> void {
        L[u] = ++ num;
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
        }
        R[u] = num;
    };

    dfs(dfs, 1, 0);

    build(1, 1, idx);

    for (int i = 1; i <= n; i++) {
        auto [op, x, val] = point[i];
        modify(1, L[x], R[x], val);
    }

    for (int i = 1; i <= idx; i++) {
        std::cout << query(1, L[i], L[i]) << " \n"[i == idx];
    }

}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
