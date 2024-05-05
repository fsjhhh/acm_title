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
    std::vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<PLL> h(n + 1);
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            h[i] = {a[i], a[1]};
        } else {
            h[i] = {a[i], a[i + 1]};
        }
        h.push_back(h[i]);
    }

    int m = n;
    n *= 2;

    std::vector dp(n + 1, std::vector<LL>(n + 1, 0));
    std::vector tmp(n + 1, std::vector<PLL>(n + 1, {-1, -1}));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        tmp[i][i] = h[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                if (tmp[i][k].second == tmp[k + 1][j].first && tmp[i][k].second != -1) {
                    if (dp[i][j] < dp[i][k] + dp[k + 1][j] + tmp[i][k].first * tmp[i][k].second * tmp[k + 1][j].second) {
                        dp[i][j] = dp[i][k] + dp[k + 1][j] + tmp[i][k].first * tmp[i][k].second * tmp[k + 1][j].second;
                        tmp[i][j] = {tmp[i][k].first, tmp[k + 1][j].second};
                    }
                }
            }
        }
    }

    LL ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = std::max(ans, dp[i][i + m - 1]);
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
