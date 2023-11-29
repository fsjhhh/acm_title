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

const int N = 1e5 + 10;
struct Node {
    int l, r;
    int val;
} tr[N * 30];
int root[N], idx;

int cnt[N], siz[N], num;

void push_up(int u) {
    tr[u].val = tr[tr[u].l].val + tr[tr[u].r].val;
}

int build(int l, int r) {
    int p = ++ idx;
    if (l == r) {
        tr[p].val = 0;
        return p;
    }
    int mid = (l + r) >> 1;
    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);
    push_up(p);
    return p;
}

int modify(int u, int l, int r, int x) {
    int p = ++ idx;
    tr[p] = tr[u];
    if (l == r) {
        tr[p].val ++ ;
        return p;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        tr[p].l = modify(tr[u].l, l, mid, x);
    } else {
        tr[p].r = modify(tr[u].r, mid + 1, r, x);
    }
    push_up(p);
    return p;
}

int query(int p, int q, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        return tr[q].val - tr[p].val;
    }
    int mid = (l + r) >> 1;
    int res = 0;
    if (L <= mid) {
        res += query(tr[p].l, tr[q].l, l, mid, L, R);
    }
    if (R > mid) {
        res += query(tr[p].r, tr[q].r, mid + 1, r, L, R);
    }
    push_up(p);
    return res;
} 

void init(int n) {
    for (int i = 0; i <= 30 * n; i++) {
        tr[i].l = tr[i].r = tr[i].val = 0;
    }
    for (int i = 0; i <= n; i++) {
        root[i] = 0;
        cnt[i] = 0;
        siz[i] = 0;
    }
    num = 0;
    idx = 0;
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    init(n);
    std::vector<std::vector<int>> edges(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    auto dfs = [&](auto self, int u, int fa) -> void {
        cnt[u] = ++ num;
        siz[u] = 1;
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            siz[u] += siz[v];
        }
    };

    dfs(dfs, 1, 0);

    root[0] = build(1, n);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        root[i] = modify(root[i - 1], 1, n, cnt[x]);
    }

    while (q -- ) {
        int l, r, x;
        std::cin >> l >> r >> x;
        int L = cnt[x], R = cnt[x] + siz[x] - 1;
        int pd = query(root[l - 1], root[r], 1, n, L, R);
        std::cout << (pd ? "YES\n" : "NO\n");
    }

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- ) {
        solve();
        std::cout << "\n";
    }
    return 0;
}
