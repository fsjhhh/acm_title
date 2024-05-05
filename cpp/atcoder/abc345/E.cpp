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
    int n, k;
    std::cin >> n >> k;

    std::vector<PLL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }

    std::vector dp(k + 1, std::vector<std::array<LL, 2>>(2, {-1, -INFL}));
    dp[0][0][0] = dp[0][0][1] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 1; j--) {
            if (dp[j][0][0] != a[i].first) {
                dp[j][0][0] = a[i].first;
                dp[j][0][1] += a[i].second;
            } else {
                dp[j][0][0] = a[i].first;
                dp[j][0][1] = dp[j][1][1] + a[i].second;
            }
            dp[j][1] = {-1, -INFL};
            for (int c = 0; c < 2; c++) {
                if (dp[j - 1][c][1] >= dp[j][0][1]) {
                    if (dp[j - 1][c][0] != dp[j][0][0]) {
                        dp[j][1] = dp[j][0];
                    }
                    dp[j][0] = dp[j - 1][c];
                } else if (dp[j - 1][c][1] >= dp[j][1][1] && (dp[j - 1][c][0] != dp[j][0][0])) {
                    dp[j][1] = dp[j - 1][c];
                }
            }
        }
        if (dp[0][0][0] != a[i].first) {
            dp[0][0][0] = a[i].first;
            dp[0][0][1] += a[i].second;
        } else {
            dp[0][0][1] = -INFL;
        }
    }

    if (dp[k][0][1] < 0) {
        std::cout << "-1\n";
    } else {
        std::cout << dp[k][0][1] << "\n";
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
