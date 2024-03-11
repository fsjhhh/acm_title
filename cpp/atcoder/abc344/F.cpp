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
    std::vector P(n, std::vector<LL>(n)), R(n, std::vector<LL>(n - 1)), D(n - 1, std::vector<LL>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> P[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            std::cin >> R[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> D[i][j];
        }
    }

    std::vector dp(n, std::vector<std::array<LL, 2>>(n, {INFL, 0}));
    dp[0][0] = {0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::vector dis(n, std::vector<LL>(n, INFL));
            dis[i][j] = 0;

            for (int x = i; x < n; x++) {
                for (int y = j; y < n; y++) {
                    if (x > 0) {
                        dis[x][y] = std::min(dis[x][y], dis[x - 1][y] + D[x - 1][y]);
                    }
                    if (y > 0) {
                        dis[x][y] = std::min(dis[x][y], dis[x][y - 1] + R[x][y - 1]);
                    }
                }
            }

            for (int x = i; x < n; x++) {
                for (int y = j; y < n; y++) {
                    if (x != n - 1 && y != n - 1) {
                        if (P[x][y] < P[i][j]) {
                            continue;
                        }
                    }
                    auto [ls_step, ls_money] = dp[i][j];
                    LL cnt = std::max(0ll, (dis[x][y] - ls_money + P[i][j] - 1) / P[i][j]);
                    LL money = ls_money + cnt * P[i][j] - dis[x][y];
                    LL step = ls_step + cnt + x - i + y - j;
                    if (step < dp[x][y][0]) {
                        dp[x][y] = {step, money};
                    } else if (step == dp[x][y][0]) {
                        if (money > dp[x][y][1]) {
                            dp[x][y] = {step, money};
                        }
                    }
                }
            }

        }
    }

    std::cout << dp[n - 1][n - 1][0] << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
