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
    int n, W;
    std::cin >> n >> W;
    std::vector<LL> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    std::vector dp(n + 1, std::vector<LL>(1 << n, INFL));

    for (int i = 0; i < n; i++) {
        dp[1][(1 << i)] = w[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= ((1 << n) - 1); j++) {
            if (dp[i][j] != INFL) {
                for (int k = 0; k < n; k++) {
                    if (j >> k & 1) {
                        continue;
                    }
                    if (dp[i][j] + w[k] <= W) {
                        dp[i][j | (1 << k)] = std::min(dp[i][j | (1 << k)], dp[i][j] + w[k]);
                    } else {
                        dp[i + 1][j | (1 << k)] = std::min(dp[i + 1][j | (1 << k)], w[k]);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i][(1 << n) - 1] != INFL) {
            std::cout << i << "\n";
            return ;
        }
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
