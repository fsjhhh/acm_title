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

const int N = 2e5 + 10;
struct Node {
    int l, r;
    int minn;
} tr[N * 30];
int root[N], idx;
int a[N], n, m;

void push_up(int u) {
    tr[u].minn = std::min(tr[tr[u].l].minn, tr[tr[u].r].minn);
}

int build(int l, int r) {
    int p = ++ idx;
    if (l == r) {
        tr[p].minn = 0;
        return p;
    }
    int mid = (l + r) >> 1;
    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);
    push_up(p);
    return p;
}

int modify(int u, int l, int r, int x, int t) {
    int p = ++ idx;
    tr[p] = tr[u];
    if (l == r) {
        tr[p].minn = t;
        return p;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        tr[p].l = modify(tr[u].l, l, mid, x, t);
    } else {
        tr[p].r = modify(tr[u].r, mid + 1, r, x, t);
    }
    push_up(p);
    return p;
}

int query(int u, int l, int r, int x) {
    if (l == r) {
        // std::cerr << l << " " << tr[l].minn << "\n";
        return l;
    }
    int mid = (l + r) >> 1;
    // std::cerr << tr[tr[u].l].minn << " " << tr[tr[u].r].minn << "\n";
    if (x > tr[tr[u].l].minn) {
        return query(tr[u].l, l, mid, x);
    } else {
        return query(tr[u].r, mid + 1, r, x);
    }
    push_up(u);
}

void solve() {
    std::cin >> n >> m;
    int z = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        z = std::max(z, a[i]);
    }

    root[0] = build(0, z + 1);

    for (int i = 1; i <= n; i++) {
        root[i] = modify(root[i - 1], 0, z + 1, a[i], i);
    }

    while (m -- ) {
        int l, r;
        std::cin >> l >> r;
        std::cout << query(root[r], 0, z + 1, l) << "\n";
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
