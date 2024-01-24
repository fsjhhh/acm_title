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

struct DSU {
    std::vector<int> dsu_p;

    DSU(int n) {
        dsu_p.resize(n);
        for (int i = 0; i < n; i++) {
            dsu_p[i] = i;
        }
    }

    int find(int u) {
        if (u != dsu_p[u]) {
            dsu_p[u] = find(dsu_p[u]);
        }
        return dsu_p[u];
    }

    void merge(int u, int v) { // 普通合并
        int fu = find(u), fv = find(v);
        if (fu == fv) {
            return ;
        }
        dsu_p[fv] = fu;
    }

};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), p;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        p.push_back(i);
    }

    std::vector<std::vector<int>> edges(n);
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u -- ;
        v -- ;
        if (a[u] == a[v]) {
            dsu.merge(u, v);
        } else {
            if (a[u] < a[v]) {
                std::swap(u, v);
            }
            edges[u].push_back(v);
        }
    }

    std::vector<int> dp(n, -INFL);
    dp[dsu.find(0)] = 1;
    
    std::sort(p.begin(), p.end(), [&](int x, int y) {
        return a[x] < a[y];
    });

    for (auto u : p) {
        for (auto v : edges[u]) {
            dp[dsu.find(u)] = std::max(dp[dsu.find(u)], dp[dsu.find(v)] + 1);
        }
    }

    std::cout << std::max(0ll, dp[dsu.find(n - 1)]) << "\n";

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}