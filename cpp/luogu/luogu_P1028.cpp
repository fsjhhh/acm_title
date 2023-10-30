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
    LL n;
    std::cin >> n;
    LL ans = 0;
    std::vector<int> f(n + 1, 0);
    auto dfs = [&](auto self, LL u) -> LL {
    	f[u] ++ ;
    	for (int i = 1; i <= u / 2; i ++ ) {
    		if (!f[i]) {
    			f[u] += self(self, i);
    		}
    		else {
    			f[u] += f[i]; 
    		}
    	}
    	return f[u];
    };
    dfs(dfs, n);
    std::cout << f[n] << "\n";
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