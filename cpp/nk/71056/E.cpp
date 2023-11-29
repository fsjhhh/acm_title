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
struct Node {
    int l, r;
    int sum, tag;
    int li, ri;
} tr[N * 4];

int n, q;
int a[N];

void push_up(int u) {
    tr[u].li = tr[u << 1].li;
    tr[u].ri = tr[u << 1 | 1].ri;
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum - tr[u << 1 | 1].li + abs(tr[u << 1].ri - tr[u << 1 | 1].li);
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u].l = tr[u].r = l;
        tr[u].sum = a[l];
        tr[u].li = tr[u].ri = a[l];
        tr[u].tag = 0;
        return ;
    }

    tr[u].l =l, tr[u].r = r;
    tr[u].tag = 0;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void push_down(int u) {
    if (!tr[u].tag) {
        return ;
    }
    tr[u << 1].sum += tr[u].tag;
    tr[u << 1].li += tr[u].tag;
    tr[u << 1].ri += tr[u].tag;
    tr[u << 1].tag += tr[u].tag;
    tr[u << 1 | 1].sum += tr[u].tag;
    tr[u << 1 | 1].li += tr[u].tag;
    tr[u << 1 | 1].ri += tr[u].tag;
    tr[u << 1 | 1].tag += tr[u].tag;
    tr[u].tag = 0;
}

void modify(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) {
        tr[u].sum += 1;
        tr[u].li += 1;
        tr[u].ri += 1;
        tr[u].tag += 1;
        return ;
    }
    push_down(u);

    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) {
        modify(u << 1, l, r);
    }
    if (r > mid) {
        modify(u << 1 | 1, l, r);
    }
    push_up(u);

}

Node query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) {
        return tr[u];
    }
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    LL ans = 0;
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
    if (!pd1 && pd2) {
        return b;
    } else if (pd1 && !pd2) {
        return a;
    } else {
        Node c;
        c.li = a.li;
        c.ri = b.ri;
        c.sum = a.sum + b.sum - b.li + abs(b.li - a.ri);
        return c;
    }
}

void solve() {
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    build(1, 1, n);

    while (q -- ) {
        int op, l, r;
        std::cin >> op >> l >> r;
        if (op == 2) {
            modify(1, l, r);
        } else {
            std::cout << query(1, l, r).sum << "\n";
        }
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
