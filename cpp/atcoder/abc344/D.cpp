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
    std::string T;
    std::cin >> T;
    int n;
    std::cin >> n;
    std::vector<std::vector<std::string>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        a[i].resize(x);
        for (int j = 0; j < x; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector dp(110, std::vector<int>(110, INF));
    dp[0][0] = 0;

    auto check = [&](std::string& x, std::string& y) -> bool {
        return x == y;
    };

    for (int i = 1; i <= n; i++) {
        for (auto it : a[i]) {
            for (int j = 0; it.size() + j <= T.size(); j++) {
                auto z = T.substr(j, it.size());
                if (check(it, z)) {
                    dp[i][j + it.size()] = std::min(dp[i][j + it.size()], dp[i - 1][j] + 1);
                }
            }
        }
        for (int j = 0; j <= T.size(); j++) {
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
        }
    }

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = std::min(ans, dp[i][T.size()]);
    }

    if (ans == INF) {
        std::cout << "-1\n";
    } else {
        std::cout << ans << '\n';
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
