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
typedef unsigned long long ULL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e6 + 10;
const ULL base = 131;

ULL p[N];
int n, q;
std::string s;

struct Node {
    int l, r;
    ULL z, f;
} tr[N * 4];

void init() {
    p[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = p[i - 1] * base;
    }
}

void push_up(int u) {
    tr[u].z = tr[u << 1].z + p[tr[u << 1].r - tr[u << 1].l + 1] * tr[u << 1 | 1].z;
    tr[u].f = tr[u << 1 | 1].f + p[tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1] * tr[u << 1].f;
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u].l = tr[u].r = l;
        tr[u].z = tr[u].f = (ULL)s[l];
        return ;
    }
    int mid = (l + r) >> 1;
    tr[u].l = l, tr[u].r = r;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void modify(int u, int l, int r, char x) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].z = tr[u].f = (ULL)x;
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
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u];
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    Node a, b;
    bool pd1 = false, pd2 = false;
    if (l <= mid) {
        pd1 = true;
        a = query(u << 1, l, r);
    }
    if (r > mid) {
        pd2 = true;
        b = query(u << 1 | 1, l, r);
    }
    push_up(u);
    if (pd1 && !pd2) {
        return a;
    } else if (!pd1 && pd2) {
        return b;
    } else {
        Node res;
        res.l = a.l, res.r = b.r;
        res.z = a.z + p[(a.r - a.l + 1)] * b.z;
        res.f = b.f + p[(b.r - b.l + 1)] * a.f;
        return res;
    }
}

void solve() {
    init();
    std::cin >> n >> q >> s;
    s = " " + s;
    
    build(1, 1, n);

    while (q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int i;
            char x;
            std::cin >> i >> x;
            modify(1, i, i, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            Node res = query(1, l, r);
            std::cout << (res.f == res.z ? "Yes\n" : "No\n");
        }
    }

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
