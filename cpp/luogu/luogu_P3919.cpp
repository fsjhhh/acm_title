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

const int N = 1e6 + 10;

struct Node {
    int l, r;
    int val;
} tr[N * 30];
int root[N], idx;

int n, m;
int a[N];

int build(int l, int r) {
    int p = ++ idx;
    if (l == r) {
        tr[p].val = a[l];
        return p;
    }
    int mid = (l + r) >> 1;
    tr[p].val = 0;
    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);
    return p;
}

int modify(int u, int l, int r, int loc, int value) {
    int p = ++ idx;
    tr[p] = tr[u];
    if (l == r && l == loc) {
        tr[p].val = value;
        return p;
    }
    int mid = (l + r) >> 1;
    if (loc <= mid) {
        tr[p].l = modify(tr[u].l, l, mid, loc, value);
    } else {
        tr[p].r = modify(tr[u].r, mid + 1, r, loc, value);
    }
    return p;
}

int query(int u, int l, int r, int loc) {
    if (l == r && l == loc) {
        return tr[u].val;
    }
    int mid = (l + r) >> 1;
    if (loc <= mid) {
        return query(tr[u].l, l, mid, loc);
    } else {
        return query(tr[u].r, mid + 1, r, loc);
    }
}

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    root[0] = build(1, n);
    for (int i = 1; i <= m; i++) {
        int v, op, loc, value;
        std::cin >> v >> op >> loc;
        if (op == 1) {
            std::cin >> value;
            root[i] = modify(root[v], 1, n, loc, value);
        } else {
            root[i] = root[v];
            std::cout << query(root[v], 1, n, loc) << "\n";
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
