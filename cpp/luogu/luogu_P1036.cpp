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
#include <iomanip> // std::fixed() std::setprecision(x) 保留x位小数
#include <array>
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

void solve()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> v[i];
    }
    std::vector<int> a(k);
    int ans = 0;

    auto isprimes = [&]() -> bool {
    	LL sum = 0;
		for (int i = 0; i < k; i ++ ) {
			sum += a[i];
		}
		for (int i = 2; i <= sum / i ; i ++ ) {
			if (sum % i == 0) {
				return false; 
			}
		}
		return true;
    };

    auto dfs = [&](auto self, int u, int x) -> void {
    	if (u == k) {
    		if (isprimes()) {
    			ans ++ ;
    		}
    		return ;
    	}
    	for (int i = x; i < n; i ++ ) {
    		a[u] = v[i];
    		self(self, u + 1, i + 1);
    	}
    };
    dfs(dfs, 0, 0);
    std::cout << ans << "\n";
}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}