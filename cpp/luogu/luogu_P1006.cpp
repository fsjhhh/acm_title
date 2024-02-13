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
    std::vector w(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> w[i][j];
        }
    }

    std::vector dp(n + m + 1, std::vector(n + 1, std::vector<int>(n + 1, 0)));
    for (int k = 2; k <= n + m; k++) {
        for (int i = 1; i <= n; i++) {
            if (k - i < 0 || k - i > m) {
                continue;
            }
            for (int j = 1; j <= n; j++) {
                if (k - j < 0 || k - j > m) {
                    continue;
                }
                dp[k][i][j] = std::max({dp[k - 1][i - 1][j - 1], dp[k - 1][i - 1][j], dp[k - 1][i][j - 1], dp[k - 1][i][j]});
                if (i == j && k - i == k - j) {
                    dp[k][i][j] += w[i][k - i];
                } else {
                    dp[k][i][j] += (w[i][k - i] + w[j][k - j]);
                }
            }
        }
    }

    std::cout << dp[n + m][n][n] << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}