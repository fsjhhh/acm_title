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
    std::vector<PLL> a(n + 1);
    for (int i = 0; i <= n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }

    auto calc = [&](PLL x, PLL y) -> double {
        LL u = x.first - y.first, v = x.second - y.second;
        return sqrt(u * u + v * v);
    };

    std::vector<double> sum(n + 2), dis(n + 2);
    for (int i = 1; i <= n; i++) {
        double x = calc(a[i], a[i - 1]);
        sum[i] = x + sum[i - 1];
        dis[i] = calc(a[0], a[i]);
    }

    std::vector<double> dp(n + 1);
    std::deque<std::pair<LL, double>> q;

    q.push_back({0, dp[0] + dis[1] - sum[1]});

    for (int i = 1; i <= n; i++) {
        while (q.size() && q.front().first + k < i) {
            q.pop_front();
        }

        dp[i] = q.front().second + sum[i] + dis[i];
        double z = dp[i] + dis[i + 1] - sum[i + 1];

        while (q.size() && q.back().second >= z) {
            q.pop_back();
        }

        q.push_back({i, z});

    }

    std::cout << std::fixed << std::setprecision(10) << dp.back() << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
