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
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    std::vector<double> dp(n + 1);

    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            dp[j + 1] = std::max(dp[j + 1], dp[j] * 0.9 + p[i]);
        }
    }

    double ans = -INFL;
    double fm = 0.0;
    for (int i = 1; i <= n; i++) {
        fm = fm * 0.9 + 1;
        ans = std::max(ans, dp[i] / fm - 1200.0 / (std::sqrt(i) * 1.0));
    }
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
