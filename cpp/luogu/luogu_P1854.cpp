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
    std::vector a(n + 1, std::vector<int>(m + 1)), f(n + 1, std::vector<int>(m + 1));
    std::vector tui(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i ++ ) {
    	for (int j = 1; j <= m; j ++ ) {
    		std::cin >> a[i][j];
    	}
    }
    for (int i = 1; i <= n; i ++ ) {
    	int sum = -INF, wei = 0;
    	for (int j = i; j <= m - n + i; j ++ ) {
    		if (sum < f[i - 1][j - 1]) {
    			tui[i][j] = j - 1;
    			wei = j - 1;
    			sum = f[i - 1][j - 1];
    		}
    		else {
    			tui[i][j] = wei;
    		}
    		f[i][j] = sum + a[i][j];
    	}
    }
    int ans = -INF;
    int z = 0;
    std::vector<int> res(n + 1);
    for (int i = n; i <= m; i ++ ) {
    	if (ans < f[n][i]) {
    		ans = f[n][i];
    		res[n] = i;
    		z = i;
    	}
    }
    std::cout << ans << "\n";
    int t = 0;
    while (z) {
    	// std::cerr << z << "\n";
    	z = tui[n - t][z];
        t ++ ;
    	// std::cout << z << " " << n - t << "\n";
    	res[n - t] = z;
    }
    for (int i = 1; i <= n; i ++ ) {
    	std::cout << res[i] << " \n"[i == n];
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