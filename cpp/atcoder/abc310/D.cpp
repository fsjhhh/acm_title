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

const int N = 20;

bool st[N][N];
bool zc[N][N];
int bt[N];
LL ans = 0;
int n, t, m;

void dfs(int u, int zu)
{
	if (zu > t + 1)
		return ;
	if (u == n + 1)
	{
		if (zu == t + 1)
		{
			ans ++ ;
			return ;
		}
		return ;
	}
	for (int i = 1; i < zu; i ++ )
	{
		bool pd = false;
		for (int j = 1; j <= n; j ++ )
		{
			if (st[i][j] && zc[u][j])
			{
				pd = true;
				break;
			}
		}
		if (!pd)
		{
			st[i][u] = true;
			dfs(u + 1, zu);
			st[i][u] = false;
		}

	}
	st[zu][u] = true;
	dfs(u + 1, zu + 1);
	st[zu][u] = false;
}

void solve()
{
    memset(bt, -1, sizeof bt);
    std::cin >> n >> t >> m;
    while (m -- )
    {
    	int a, b;
    	std::cin >> a >> b;
    	zc[a][b] = zc[b][a] = true;
    }

    dfs(1, 1);
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

