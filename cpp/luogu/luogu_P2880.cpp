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
int n, q;
int a[N], tr_max[N], tr_min[N];

int lowbit(int x) {
    return x & (-x);
}

void modify(int u, int x) {
    for (int i = u; i <= n; i += lowbit(i)) {
        tr_max[i] = std::max(tr_max[i], x);
        tr_min[i] = std::min(tr_min[i], x);
    }
}

int query_max(int l, int r) {
    if (r > l) {
        if (r - lowbit(r) > l) {
            return std::max(tr_max[r], query_max(l, r - lowbit(r)));
        } else {
            return std::max(a[r], query_max(l, r - 1));
        }
    } else {
        return a[l];
    }
}

int query_min(int l, int r) {
    if (r > l) {
        if (r - lowbit(r) > l) {
            return std::min(tr_min[r], query_min(l, r - lowbit(r)));
        } else {
            return std::min(a[r], query_min(l, r - 1));
        }
    } else {
        return a[l];
    }
}

void solve() {

    memset(tr_min, 0x3f, sizeof tr_min);

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        modify(i, a[i]);
    }

    while (q -- ) {
        int l, r;
        std::cin >> l >> r;
        std::cout << query_max(l, r) - query_min(l, r) << "\n";
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

