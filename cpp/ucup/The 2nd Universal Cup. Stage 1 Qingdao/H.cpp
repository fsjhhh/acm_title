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

#define int long long

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    s = " " + s;
    std::vector<LL> dp(n + 1);
    for (int i = 1; i <= n; i ++ ) {
    	if (s[i] == '1') {
    		if (i == 1) {
    			dp[i] = n;
    		}
    		else {
    			if (s[i - 1] == s[i]) {
    				dp[i] = (n - i + 1) * (i - 1) * 2 + (n - i + 1) + dp[i - 1];
    			}
    			else {
    				dp[i] = (n - i + 1) * (i - 1) + (n - i + 1) + dp[i - 1];
    			}
    		}
    	}
    	else {
    		if (i == 1) {
    			dp[i] = n * 2;
    		}
    		else {
    			if (s[i - 1] == s[i]) {
    				dp[i] = (n - i + 1) * (i - 1) * 2 + (n - i + 1) * 2 + dp[i - 1];
    			}
    			else {
    				dp[i] = (n - i + 1) * (i - 1) + (n - i + 1) * 2 + dp[i - 1];
    			}
    		}
    	}
    }
    std::cout << dp[n] << "\n";
}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}