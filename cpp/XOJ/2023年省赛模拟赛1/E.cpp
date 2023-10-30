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
//#include <bits/stdc++.h>
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> st(n + 1), a(n + 1);
    int sum = 0, ans = 0, cnt = 0;
    auto dfs = [&](auto self, int u) {
    	if (u == n) {
    		for (int i = 1; i <= n; i ++ ) {
    			if (i > m && a[i] > i && a[i] != i) {
    				return ;
    			}
    		}
			// for (int i = 1; i <= n; i ++ ) {
    		// 	std::cout << a[i] << " \n"[i == n];
    		// }
    		sum ++ ;
    		if (a[n] == n) {
    			ans ++ ;
    		}
    		return ;
    	}

    	for (int i = 1; i <= n; i ++ ) {
    		if (!st[i]) {
    			st[i] = true;
    			a[u + 1] = i;
    			self(self, u + 1);
    			st[i] = false; 
    		}
    	}
    };

    dfs(dfs, 0);
    double e = (ans * 1.0) / (sum * 1.0);
    std::cout << std::fixed << std::setprecision(10) << e << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}