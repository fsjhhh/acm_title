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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> v[i];
    }
    std::vector<std::vector<int>> d(m + 1);
    std::vector<int> f(m + 1, INF);
    for (int i = 0, j = 0; i < n; i ++ ) {
    	if (v[i] <= m) {
    		j = i;
    		while (v[j + 1] == v[j] + 1 && v[j + 1] <= m && j + 1 < n) {
    			j ++ ;
    		}    	
    		d[v[i] - 1].push_back(v[j]);
    		i = j;
    	}
    }
    f[0] = 0;
    for (int i = 0, j = 1; i <= m; i ++ ) {
    	for (auto it : d[i]) {
    		while (j <= it) {
    			f[j] = std::min(f[j], f[i] + 1);
    			j ++ ;
    		}
    	}
    }
    if (f[m] == INF) {
    	std::cout << "-1\n";
    	return ;
    }
    std::cout << f[m] << "\n";
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}