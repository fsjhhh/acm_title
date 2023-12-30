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

const int N = 2e5 + 10;
const int mod = 998244353;
struct Node {
    int l, r;
    int cnt;
    int sum;
    int tag;
} tr[N * 4];
int a[N], n, m;

LL pow(int x, int y) {
    LL res = 1;
    while (y) {
        if (y & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

LL inv(int x) {
    return pow(x, mod - 2);
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u].l = tr[u].r = l;
        tr[u].cnt = 1;
        tr[u].sum = a[l];
        tr[u].tag = 0;
        return ;
    }

    tr[u].l = l, tr[u].r = r;
    tr[u].cnt = 1;
    tr[u].tag = 0;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    tr[u].sum = 0;
}

void push_down(int u) {
    tr[u << 1].cnt = (tr[u << 1].cnt * tr[u].cnt) % mod;
    tr[u << 1].tag = (tr[u << 1].tag * tr[u].cnt + tr[u].tag) % mod;
    tr[u << 1 | 1].cnt = (tr[u << 1 | 1].cnt * tr[u].cnt) % mod;
    tr[u << 1 | 1].tag = (tr[u << 1 | 1].tag * tr[u].cnt + tr[u].tag) % mod;
    if (tr[u << 1].l == tr[u << 1]. r) {
        tr[u << 1].sum = (tr[u << 1].cnt * tr[u << 1].sum % mod + tr[u << 1].tag) % mod;
        tr[u << 1].cnt = 1;
        tr[u << 1].tag = 0;
    }
    if (tr[u << 1 | 1].l == tr[u << 1 | 1].r) {
        tr[u << 1 | 1].sum = (tr[u << 1 | 1].cnt * tr[u << 1 | 1].sum % mod + tr[u << 1 | 1].tag) % mod;
        tr[u << 1 | 1].cnt = 1;
        tr[u << 1 | 1].tag = 0;
    }
    tr[u].cnt = 1;
    tr[u].tag = 0;
}

void modify(int u, int l, int r, int x) {
    if (tr[u].l >= l && tr[u].r <= r) {
        int len = (r - l + 1);
        int inv_len = inv(len);
        int z = inv_len * (len - 1) % mod;
        tr[u].cnt = tr[u].cnt * z % mod;
        tr[u].tag = (tr[u].tag * z % mod + inv_len * x) % mod;
        if (tr[u].l == tr[u].r) {
            tr[u].sum = (tr[u].cnt * tr[u].sum % mod + tr[u].tag) % mod;
            tr[u].cnt = 1;
            tr[u].tag = 0;
        }
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
}


int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].sum;
    }
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    LL ans = 0;
    if (l <= mid) {
        (ans += query(u << 1, l, r)) %= mod;
    } 
    if (r > mid) {
        (ans += query(u << 1 | 1, l, r)) %= mod;
    }
    return ans;
}

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    build(1, 1, n);

    while (m -- ) {
        int l, r, x;
        std::cin >> l >> r >> x;
        modify(1, l, r, x);
    }

    for (int i = 1; i <= n; i++) {
        std::cout << query(1, i, i) << " \n"[i == n];
    }

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
