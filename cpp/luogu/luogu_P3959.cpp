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
    int n, m;
    std::cin >> n >> m;
    std::vector mp(n, std::vector<LL>(n, INFL));

    for (int i = 0; i < m; i++) {
        int u, v;
        LL w;
        std::cin >> u >> v >> w;
        u -- ;
        v -- ;
        mp[u][v] = std::min(mp[u][v], w);
        mp[v][u] = std::min(mp[v][u], w);
    }

    std::vector w((1 << n), std::vector<LL>(n, INFL));

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < (1 << n); j++) {
            for (int k = 0; k < n; k++) {
                if ((1 << k & j) && (!(1 << i & j))) {
                    w[j][i] = std::min(w[j][i], mp[k][i]);
                }
            }
        }
    }

    LL ans = INFL;

    std::vector  dp(n, std::vector<LL>((1 << n), INFL));
    for (int i = 0; i < n; i++) {
        dp[0][1 << i] = 0;
    }

    for (int i = 1; i < (1 << n); i++) {
        for (int j = i; j != 0; j = (j - 1) & i) {
            LL sum = 0;
            for (int k = 0; k < n; k++) {
                if (1 << k & (i - j)) {
                    if (w[j][k] < ans) {
                        sum += w[j][k];
                    } else {
                        sum = INF;
                    }
                }
            }
            for (int k = 1; k < n; k++) {
                dp[k][i] = std::min(dp[k - 1][j] + (LL)sum * k, dp[k][i]);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        ans = std::min(ans, dp[i][(1 << n) - 1]);
    }

    if (ans >= INFL) {
        std::cout << 0 << "\n";
    } else {
        std::cout << ans << "\n";
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
