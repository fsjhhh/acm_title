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
    int n, d;
    std::cin >> n >> d;
    std::vector<LL> a(n);
    LL tot = 0;
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    	tot += a[i];
    }
    double ave = (tot * 1.0) / (d * 1.0);
    int up = (1 << n);
    std::vector<double> cost(up, 0);
    for (int i = 0; i < up; i++) {
    	for (int j = 0; j < n; j++) {
    		cost[i] += a[j] * (i >> j & 1);
    	}
    	cost[i] = (cost[i] - ave) * (cost[i] - ave);
    }

    std::vector<double> dp(up, (double)INFL);
    dp[0] = 0;
    for (int i = 1; i <= d; i++) {
    	std::vector<double> dp2(up, (double)INFL);
    	for (int j = 0; j < up; j++) {
    		for (int k = j; ; k = ((k - 1) & j)) {
    			if (dp[j ^ k] != (double)INFL) {
    				dp2[j] = std::min(dp2[j], dp[j ^ k] + cost[k]);
    			}
    			if (k == 0) {
    				break;
    			}
    		}
    	}
    	dp.swap(dp2);
    }

    std::cout << std::fixed << std::setprecision(15) << dp.back() / (d * 1.0) << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}