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
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector dp(n + 2, std::vector(n + 2, std::vector<int> (n + 2, INF)));
    dp[0][1][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            for (int k = 0; k <= n; k++) {
                int l = std::max(i - a[i] + 1, 1), r = std::min(i + a[i] - 1, n);
                dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j][k]);
                
                if (l <= j) {
                    if (i > k) {
                        dp[i][i + 1][i] = std::min(dp[i][i + 1][i], dp[i - 1][j][k] + 1);
                    } else {
                        dp[i][k + 1][k] = std::min(dp[i][k + 1][k], dp[i - 1][j][k] + 1);
                    }
                } else {
                    if (i > k) {
                        dp[i][j][i] = std::min(dp[i][j][i], dp[i - 1][j][k] + 1);
                    } else {
                        dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j][k] + 1);
                    }
                }

                if (r > k) {
                    if (i <= j) {
                        dp[i][r + 1][r] = std::min(dp[i][r + 1][r], dp[i - 1][j][k] + 1);
                    } else {
                        dp[i][j][r] = std::min(dp[i][j][r], dp[i - 1][j][k] + 1);
                    }
                } else {
                    if (i <= j) {
                        dp[i][k + 1][k] = std::min(dp[i][k + 1][k], dp[i - 1][j][k] + 1);
                    } else {
                        dp[i][j][k] = std::min(dp[i][j][k], dp[i - 1][j][k] + 1);
                    }
                }

            }
        }
    }

    std::cout << dp[n][n + 1][n] << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
