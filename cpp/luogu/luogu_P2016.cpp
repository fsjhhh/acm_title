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
    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < n; i++) {
        int u, v, k;
        std::cin >> u >> k;
        for (int j = 0; j < k; j++) {
            std::cin >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
    }

    std::vector<std::array<int, 2>> dp(n);

    auto dfs = [&](auto self, int u, int fa) -> void {
        dp[u][1] ++ ;
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }

            self(self, v, u);
            dp[u][0] += dp[v][1];
            dp[u][1] += std::min(dp[v][0], dp[v][1]);
        }
    };

    dfs(dfs, 0, -1);

    std::cout << std::min(dp[0][0], dp[0][1]) << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
