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
    std::vector w(n + 1, std::vector<int>(n + 1, 0));
    while (1) {
        int x, y, s;
        std::cin >> x >> y >> s;
        if (!x) {
            break;
        }
        w[x][y] = s;
    }

    std::vector dp(2 * n + 1, std::vector(n + 1, std::vector<int>(n + 1, 0)));
    for (int k = 1; k <= 2 * n; k++) {
        for (int i = 1; i <= n; i++) {
            if (k - i < 0 || k - i > n) {
                continue;
            }
            for (int j = 1; j <= n; j++) {
                if (k - j < 0 || k - j > n) {
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

    std::cout << dp[2 * n][n][n] << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}