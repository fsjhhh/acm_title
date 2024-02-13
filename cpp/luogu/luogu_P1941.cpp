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

struct node {
	int p, l, h;
};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> up(n), down(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> up[i] >> down[i];
    }

    std::vector<node> d(k);
    for (int i = 0; i < k; i++) {
    	std::cin >> d[i].p >> d[i].l >> d[i].h;
    }

    std::sort(d.begin(), d.end(), [&](node a, node b) -> bool {
    	return a.p < b.p;
    });

    std::vector dp(n + 1, std::vector<int>(m * 2 + 1, INF));
    for (int i = 1; i <= m; i++) { // 初始化
    	dp[0][i] = 0;
    }

    int cnt = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
    	for (int j = up[i - 1] + 1; j <= up[i - 1] + m; j++) { // 完全背包
    		dp[i][j] = std::min(dp[i][j - up[i - 1]], dp[i - 1][j - up[i - 1]]) + 1;
    	}
    	for (int j = m + 1; j <= up[i - 1] + m; j++) { // 大于m都是m
    		dp[i][m] = std::min(dp[i][m], dp[i][j]);
    	}
    	for (int j = 1; j <= m - down[i - 1]; j++) { // 01背包
    		dp[i][j] = std::min(dp[i][j], dp[i - 1][j + down[i - 1]]);
    	}
    	if (cnt < k && i == d[cnt].p) { // 管道设为INF
    		for (int j = 0; j <= d[cnt].l; j++) {
    			dp[i][j] = INF;
    		}
    		for (int j = d[cnt].h; j <= m; j++) {
    			dp[i][j] = INF;
    		}
    		cnt ++ ;
    	}

    	int ans = INF;
    	for (int j = 1; j <= m; j++) { // 判断是否能通过
    		ans = std::min(ans, dp[i][j]);
    	}

    	if (ans == INF) {
    		ok = false;
    		break;
    	}

    }

    if (ok) {
    	std::cout << "1\n";
    	int ans = INF;
    	for (int j = 1; j <= m; j++) {
    		ans = std::min(ans, dp[n][j]);
    	}
    	std::cout << ans << "\n";
    } else {
    	std::cout << "0\n";
    	std::cout << cnt - 1 << "\n";
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