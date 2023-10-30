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
    int n, m;
    std::cin >> n >> m;
    int x = n / m, y = n / m + 1;
    double px = ((x * 1.0) / (n * 1.0)), py = ((y * 1.0) / (n * 1.0));
    int cy = n % m, cx = m - n % m;
    std::vector dp(m + 1, std::vector<double>(m + 1));
    for (int i = 0; i <= cx; i ++ ) {
    	for (int j = 0; j <= cy; j ++ ) {
    		if (i + j) {
    			double t = (px * i + py * j);
    			if(i) {
    				dp[i][j] += (px * i * 1.0) / t * dp[i - 1][j]; 
    			}
    			if (j) {
    				dp[i][j] += (py * j * 1.0) / t * dp[i][j - 1];
    			}
    			dp[i][j] += (1.0 / t);
    		}
    	}
    }
    std::cout << std::fixed << std::setprecision(10) << dp[cx][cy] << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}