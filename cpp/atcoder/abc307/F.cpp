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

const int N = 3e5 + 10;
std::vector<PLL> g[N];
LL ans[N], dis[N], ds[N];
LL n, m, k, day;
std::priority_queue<PLL> q;

void dijkstra()
{
	for (int i = 1; i <= day; i ++ )
	{
		std::vector<LL> ins;
		while (q.size())
		{
			auto [di, u] = q.top();
			if (dis[u] > ds[i])
				break;
			q.pop();
			if (ans[u] != -1)
				continue;
			ans[u] = i;
			ins.push_back(u);
			for (auto [v, val] : g[u])
			{
	    		if (dis[v] > dis[u] + val)
	    		{
	    			dis[v] = dis[u] + val;
	    			q.push({-dis[v], v});
	    		}
			}
		}
		for (auto u : ins)
		{
			for (auto [v, val] : g[u])
			{
				if (dis[v] > val)
				{
					dis[v] = val;
					q.push({-dis[v], v});
				}
			}
		}
	}
}

void solve()
{
	memset(ans, -1, sizeof ans);
	memset(dis, 0x3f, sizeof dis);
    std::cin >> n >> m;
    for (LL i = 1; i <= m; i ++ )
    {
 		int a, b, c;
 		std::cin >> a >> b >> c;
 		g[a].push_back({b, c});
 		g[b].push_back({a, c});   	
    }

    std::cin >> k;
    for (int i = 1; i <= k; i ++ )
    {
    	int u;
    	std::cin >> u;
    	dis[u] = 0;
    	ans[u] = 0;
    	for (auto [v, val] : g[u])
    	{
    		if (dis[v] > dis[u] + val)
    		{
    			dis[v] = dis[u] + val;
    			q.push({-dis[v], v});
    		}
    	}
    }

    std::cin >> day;
    for (int i = 1; i <= day; i ++ )
    	std::cin >> ds[i];

    dijkstra();

    for (int i = 1; i <= n; i ++ )
    	std::cout << ans[i] << "\n";

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