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
    LL n, m;
    std::cin >> n >> m;
    std::vector<PLL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }

    std::vector<std::array<LL, 2>> dp(m + 1, {INFL, INFL});
    dp[0][0] = dp[0][1] = 0;

    for (int i = 0; i < n; i++) {
        std::vector<std::array<LL, 2>> dp1 = dp;
        for (int j = 0; j <= m; j++) {
            dp1[std::min(m, j + a[i].first)][0] = std::min({dp[std::min(m, j + a[i].first)][0], dp[j][0] + a[i].second});
            dp1[std::min(m, j + 2 * a[i].first)][1] = std::min({dp1[std::min(m, j + 2 * a[i].first)][1], dp[std::min(m, j + 2 * a[i].first)][1], dp[j][0] + a[i].second / 2});
            dp1[std::min(m, j + a[i].first)][1] = std::min({dp1[std::min(m, j + a[i].first)][1], dp[std::min(m, j + a[i].first)][1], dp[j][1] + a[i].second});
        }
        std::swap(dp, dp1);
        // for (int j = 0; j <= m; j++) {
        //     std::cout << j << " " << dp[j][0] << ' ' << dp[j][1] << "\n";
        // } 
        // std::cout << "\n";
    }

    std::cout << std::min(dp[m][0], dp[m][1]) << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
