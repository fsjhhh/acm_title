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
    int s, n, m;
    std::cin >> s >> n >> m;

    std::vector a(n, std::vector<int>(s));
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[j][i];
        }
    }

    for (int i = 0; i < n; i++) {
        std::sort(a[i].begin(), a[i].end());
    }

    std::vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int k = m; k >= 0; k--) {
            for (int j = 0; j < s; j++) {
                if (k > a[i][j] * 2) {
                    dp[k] = std::max(dp[k], dp[k - a[i][j] * 2 - 1] + (i + 1) * (j + 1));
                }
            }
        }
    }

    // int ans = 0;
    // for (int i = 0; i <= m; i++) {
    //     ans = std::max(ans, dp[i]);
    // }

    std::cout << dp[m] << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
