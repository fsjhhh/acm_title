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
// #include <bits/stdc++.h>
// priority_queue 优先队列
// std::cout.flush(); 交互题
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<PLL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }

    std::sort(a.begin() + 1, a.end(), [&](PLL x, PLL y) -> bool{
        return x.second > y.second;
    });

    std::vector dp(n + 1, std::vector<std::array<LL, 2>>(n + 1, {INFL, INFL}));
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = {0, 0};
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j][0] = std::min(dp[i - 1][j][0], dp[i - 1][j - 1][0] + a[i].first + a[i].second);
                dp[i][j][1] = std::min(dp[i - 1][j][1], dp[i][j][0] - a[i].second);
            } else {
                dp[i][j][0] = std::min(dp[i - 1][j][0], dp[i - 1][j - 1][0] + a[i].first);
                dp[i][j][1] = std::min(dp[i - 1][j][1], dp[i][j][0] - a[i].second);
            }
        }
    }

    LL ans = 0;
    for (LL i = 0; i <= n; i++) {
        if (dp[n][i][1] <= m) {
            ans = std::max(ans, i);
        }
    }

    std::cout << ans << "\n";
    
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
