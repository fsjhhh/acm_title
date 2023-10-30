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

const int N = 2e5 + 10;
LL c[N], p[N];
LL d[N];
std::vector<int> v[N];
bool st[N];

void dfs(int u)
{
	if (!v[u].size() || st[u])
	{
		d[u] = c[u];
		return ;
	}
	LL ans = 0;
	for (auto it : v[u])
	{
		if (!st[it])
		{
			dfs(it);
			st[it] = true;
		}
		ans += d[it];
	}
	d[u] = std::min(ans, c[u]);
}

void solve()
{
	memset(d, 0x3f, sizeof d);
	memset(st, 0, sizeof st);
    LL n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i ++ )
    	v[i].clear();
    for (int i = 1; i <= n; i ++ )
    	std::cin >> c[i];
    
    for (int i = 1; i <= k; i ++ )
    {
    	int x;
    	std::cin >> x;
    	c[x] = 0;
    	d[x] = 0;
    	st[x] = true;
    }

    for (int i = 1; i <= n; i ++ )
  	{
  		int m;
  		std::cin >> m;
  		for (int j = 1; j <= m; j ++ )
  		{
  			int t;
  			std::cin >> t;
  			v[i].push_back(t);
  		}
  	}

  	for (int i = 1; i <= n; i ++ )
  	{
  		if (!st[i])
  			dfs(i);
  	}

  	for (int i = 1; i <= n; i ++ )
  		std::cout << d[i] << " \n"[i == n];

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