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

const int N = 2e5 + 10;
struct node {
    int l, r;
    int lazy;
    int minn;
} tr[N * 4];

void init(int n) {
    for (int i = 0; i <= 4 * n; i++) {
        tr[i].l = tr[i].r = tr[i].lazy = tr[i].minn = 0;
    }
}

void push_up(int u) {
    tr[u].minn = std::min(tr[u << 1].minn, tr[u << 1 | 1].minn);
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u].l = tr[u].r = l;
        tr[u].lazy = 0;
        tr[u].minn = INF;
        return ;
    }
    tr[u].l = l, tr[u].r = r;
    tr[u].lazy = 0;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void push_down(int u) {
    if (!tr[u].lazy) {
        return ;
    }
    tr[u << 1].lazy = 1;
    tr[u << 1].minn = tr[u].minn;
    tr[u << 1 | 1].lazy = 1;
    tr[u << 1 | 1].minn = tr[u].minn;
    tr[u].lazy = 0;
}

void modify(int u, int l, int r, int x) {
    if (l <= tr[u].l && r >= tr[u].r) {
        tr[u].lazy = 1;
        tr[u].minn = x;
        return ;
    }
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) {
        modify(u << 1, l, r, x);
    }
    if (r > mid) {
        modify(u << 1 | 1, l, r, x);
    }
    push_up(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) {
        return tr[u].minn;
    }
    push_down(u);
    int ans = INF;
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) {
        ans = std::min(ans, query(u << 1, l, r));
    }
    if (r > mid) {
        ans = std::min(ans, query(u << 1 | 1, l, r));
    }
    push_up(u);
    return ans;
}

void solve() {
    int n;
    std::cin >> n;
    init(n);
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = n; i >= 1; i--) {
        std::cin >> a[i];
    }

    build(1, 1, n);
    std::vector<int> l(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (l[a[i]] == -1) {
            l[a[i]] = i;
            b[i] = 1;
            modify(1, i, i, 1);
        } else {
            int t = query(1, l[a[i]], i - 1);
            l[a[i]] = i;
            b[i] = t + 1;
            modify(1, i, i, b[i]);
        }
    }

    std::cout << b[n] << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
