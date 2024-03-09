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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> col(n, 0);

    for (int i = 0; i < n; i++) {
        std::cin >> col[i];
    }

    std::vector<std::vector<int>> edges(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u -- ;
        v -- ;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    std::vector<std::map<int, LL>> mp(n);

    LL ans = 0;

    auto merge = [&](int u, int v) -> void {
        if (mp[u].size() < mp[v].size()) {
            std::swap(mp[u], mp[v]);
        }

        for (auto [x, y] : mp[v]) {
            mp[u][x] += y;
        }
    };

    auto dfs = [&](auto self, int u, int fa) -> void {
        mp[u][col[u]] ++ ;
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }

            self(self, v, u);

            if (mp[v][col[u]]) {
                ans += (mp[v][col[u]] * (mp[v][col[u]] - 1) / 2);
            }

            merge(u, v);

        }
        ans += (mp[u][col[u]] - 1);

        mp[u][col[u]] = 1;

    };

    dfs(dfs, 0, -1);

    for (auto [x, y] : mp[0]) {
        ans += (y * (y - 1) / 2);
    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
