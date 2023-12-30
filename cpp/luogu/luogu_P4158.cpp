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

void solve() {
    int n, m, t;
    std::cin >> n >> m >> t;
    std::vector<std::string> mp(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> mp[i];
        mp[i] = " " + mp[i];
    }

    std::vector dp(n + 1, std::vector(m + 1, std::vector<std::array<int, 2>>(t + 1)));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == 1) {
                for (int k = 1; k <= t; k++) {
                    dp[i][j][k][0] = std::max(dp[i - 1][m][k - 1][0], dp[i - 1][m][k - 1][1]);
                    dp[i][j][k][1] = std::max(dp[i - 1][m][k - 1][0] + 1, dp[i - 1][m][k - 1][1] + 1);
                }
                continue;
            }
            if (mp[i][j] == mp[i][j - 1]) {
                for (int k = 1; k <= t; k++) {
                    dp[i][j][k][1] = std::max(dp[i][j - 1][k][1] + 1, dp[i][j - 1][k - 1][0] + 1);
                    dp[i][j][k][0] = std::max(dp[i][j - 1][k - 1][1], dp[i][j - 1][k][0]);
                }
            } else {
                for (int k = 1; k <= t; k++) {
                    dp[i][j][k][1] = std::max(dp[i][j - 1][k][0] + 1, dp[i][j - 1][k - 1][1] + 1);
                    dp[i][j][k][0] = std::max(dp[i][j - 1][k][1], dp[i][j - 1][k - 1][0]);
                }
            }
        }
    }

    std::cout << std::max(dp[n][m][t][0], dp[n][m][t][1]) << "\n";


}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
