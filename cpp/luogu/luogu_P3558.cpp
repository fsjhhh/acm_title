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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::array<int, 3>> dp(n);
    dp[0][0] = dp[0][1] = dp[0][2] = INF;
    dp[0][a[0] + 1] = 0;
    
    for (int i = 1; i < n; i++) {
        if (a[i] == -1) {
            dp[i][0] = dp[i - 1][0];
            if (a[i - 1] == 1) {
                dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + 1;
            } else {
                dp[i][1] = INF;
            }
            if (a[i - 1] == 1) {
                dp[i][2] = std::min(std::min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + 2;
            } else {
                dp[i][2] = dp[i - 1][2] + 2;
            }
        } else if (a[i] == 0) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]);
            if (a[i - 1] == 1) {
                dp[i][2] = std::min(std::min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + 1;
            } else {
                dp[i][2] = dp[i - 1][2] + 1;
            }
        } else {
            dp[i][0] = dp[i - 1][0] + 2;
            if (a[i - 1] == -1) {
                dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][0]) + 1;
            } else {
                dp[i][1] = dp[i - 1][0] + 1;
            }
            dp[i][2] = std::min(std::min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
        }
    }

    int ans = std::min(std::min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    if (ans == INF) {
        std::cout << "BRAK\n";
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
