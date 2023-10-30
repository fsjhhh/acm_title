// Problem: 找孙子
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/62880/M
// Memory Limit: 524288 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

const int N = 2e6 + 10;
std::vector<int> edges[N];
int n, m;

LL ans;
LL d[N], siz[N];
bool st[N];

void dfs(int u) {
	siz[u] = 1; 
	for (int v : edges[u]) {
		if (!st[v]) {
			st[v] = true;
			dfs(v);
		}
		siz[u] += siz[v];
	}
}

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) {
    	int u, v;
    	std::cin >> u >> v;
    	edges[u].push_back(v);
    	d[v] ++ ;
    }
    
    for (int i = 1; i <= n; i ++ ) {
    	if (!d[i]) {
    		st[i] = true;
    		dfs(i);
    	}
    }
    
    for (int i = 1; i <= n; i ++ ) {
    	LL ans = 0;
    	for (auto v : edges[i]) {
    		ans += edges[v].size();
    	}
    	std::cout << ans << " ";
    }
    
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