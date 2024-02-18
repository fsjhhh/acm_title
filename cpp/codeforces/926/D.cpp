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

const LL mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u -- , v -- ;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    std::vector<std::array<LL, 3>> dp(n);
    auto dfs = [&](auto self, int u, int fa) -> void {
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
        }

        for (int t = 0; t < 2; t++) {
            std::array<LL, 3> g{};
            g[t] = 1;
            for (auto v : edges[u]) {
                if (v == fa) {
                    continue;
                }
                std::array<LL, 3> ng{};
                for (int i = 0; i <= 2; i++) {
                    for (int j = 0; j + t <= 2 && i + j <= 2; j++) {
                        (ng[std::max(i, j + t)] += g[i] * dp[v][j] % mod) %= mod;
                    }
                }
                g = ng;
            }
            for (int i = 0; i <= 2; i++) {
                dp[u][i] = (dp[u][i] + g[i]) % mod;
            }
        }

    };

    dfs(dfs, 0, -1);

    LL ans = (dp[0][0] + dp[0][1] + dp[0][2]) % mod;

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
