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
    std::vector<int> s(n), f(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> s[i] >> f[i];
    }

    std::vector<int> dp(900010, -INF);
    dp[400000] = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] < 0) {
    		for (int j = 0; j <= 800000 + s[i]; j++) {
    			dp[j] = std::max(dp[j], dp[j - s[i]] + f[i]);
    		}
    	} else {
    		for (int j = 800000; j >= s[i]; j--) {
    			dp[j] = std::max(dp[j], dp[j - s[i]] + f[i]);
    		}
    	}
    }

    int ans = -INF;
    for (int j = 400000; j <= 800000; j++) {
    	if (dp[j] >= 0) {
    		ans = std::max(ans, j + dp[j] - 400000);
    	}
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