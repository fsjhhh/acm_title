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
// #include <bits/stdc++.h>
// priority_queue 优先队列
// std::cout.flush(); 交互题
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

int a[N];

struct Node {
    int l, r;
    int lazy;
    int sum;
    int mx;
} tr[N * 4];

void init(int n) {
    for (int i = 0; i <= 4 * n; i++) {
        tr[i].l = tr[i].r = tr[i].sum = 0, tr[i].mx = -INFL;
        tr[i].lazy = -1;
    }
}

void push_up(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].mx = std::max(tr[u << 1].mx, tr[u << 1].sum + tr[u << 1 | 1].mx);
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u].l = tr[u].r = l;
        tr[u].lazy = -1;
        tr[u].sum = a[l];
        tr[u].mx = -a[l];
        return ;
    }
    tr[u].l = l, tr[u].r = r;
    tr[u].lazy = -1;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void modify(int u, int l, int r, int x) {
    if (l <= tr[u].l && r >= tr[u].r) {
        tr[u].lazy = x;
        tr[u].sum = x * (tr[u].r - tr[u].r + 1);
        tr[u].mx = -x;
        return ;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) {
        modify(u << 1, l, r, x);
    }
    if (r > mid) {
        modify(u << 1 | 1, l, r, x);
    }
    push_up(u);
}

Node query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) {
        return tr[u];
    }
    Node ans;
    int mid = (tr[u].l + tr[u].r) >> 1;
    bool ok = false;
    if (l <= mid) {
        ok = true;
        ans = query(u << 1, l, r);
    }
    if (r > mid) {
        if (ok) {
            Node res = query(u << 1 | 1, l, r);
            int t = ans.sum + res.mx;
            ans.sum += res.sum;
            ans.mx = std::max(ans.mx, t);
        } else {
            ans = query(u << 1 | 1, l, r);
        }
    }
    push_up(u);
    return ans;
}


void solve() {
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    init(n);
    build(1, 1, n);

    while (q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            a[x] = y;
            modify(1, x, x, y);
        } else {
            int l, r;
            std::cin >> l >> r;
            Node sum = query(1, l + 1, r);
            std::cout << sum.mx + a[l] << "\n";
        }
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
