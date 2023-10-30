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
#include <ranges>
#include <functional>
// #include <bits/stdc++.h>
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> a[i];
    }

    for (auto it : a | std::views::reverse) {
    	std::cout << it << " ";
    }
    std::cout << "\n";

    std::vector<int> dp(k + 1);
    for (int i = 1; i <= k; i ++ ) {
    	for (int j = 0; j < n; j ++ ) {
    		if (i - a[j] < 0) {
    			continue;
    		}
    		dp[i] |= (dp[i - a[j]] == 0);
    	}
    }
    std::cout << (dp[k] ? "First" : "Second") << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}