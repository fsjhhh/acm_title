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
    std::vector qw(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> edges(n + 1);
    for (int i = 0; i < m; i ++ ) {
    	int a, b, w;
    	std::cin >> a >> b >> w;
    	edges[a].push_back(b);
    	edges[b].push_back(a);
    	qw[a][b] = w;
    	qw[b][a] = w;
    }

    LL ans = 0;
    std::vector<bool> st(n + 1, false);
    auto dfs = [&](auto self, int u, LL sum) -> void {
    	ans = std::max(ans, sum);
    	for (auto it : edges[u]) {
    		if (!st[it]) {
    			st[it] = true;
    			self(self, it, sum + qw[u][it]);
    			st[it] = false;
    		}
    	}
    };

    for (int i = 1; i <= n; i ++ ) {
    	for (int i = 1; i <= n; i ++ ) {
    		st[i] = false;
    	}
    	st[i] = true;
    	dfs(dfs, i, 0);
    }
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