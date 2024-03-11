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
    std::vector<PLL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }

    std::vector<LL> b(m + 1);
    for (int i = 1; i <= m; i++) {
        std::cin >> b[i];
    }

    auto calc = [&](int l, int r) -> LL {
        std::vector dp(r + 5, std::vector<LL>(r - l + 5, INFL));
        dp[l][0] = a[l].first;
        dp[l][1] = std::max(0ll, a[l].first - a[l].second);
        for (int i = l + 1; i <= r; i++) {
            dp[i][0] = std::min(dp[i][0], dp[i - 1][0] + a[i].first);
            for (int j = 1; j <= (i - l + 1); j++) {
                dp[i][j] = std::min({dp[i][j], dp[i - 1][j] + a[i].first, std::max(0ll, dp[i - 1][j - 1] + a[i].first - a[i].second)});
            }
        }

        for (int i = 0; i <= (r - l + 1); i++) {
            if (!dp[r][i]) {
                return i;
            }
        }

        return -1;

    };

    LL ans = 0;
    for (int i = 1; i <= m; i++) {
        LL t = calc(b[i - 1] + 1, b[i]);
        if (t == -1) {
            std::cout << "-1\n";
            return ;
        }

        ans += t;

    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
