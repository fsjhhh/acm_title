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

const int N = 2e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx;
int n, a[N], res[N];

void add(int x, int y)
{
	e[idx] = y, ne[idx] = h[x], h[x] = idx ++ ;
}

void dfs(int u)
{
	res[u] = 1;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (a[u] > a[j])
		{
			if (res[j] == 0)
				dfs(j);
			res[u] += res[j];
		}
	}
}

void solve(int t)
{
	memset(res, 0, sizeof res);
	memset(h, -1, sizeof h);
	idx = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i];
    for (int i = 1; i < n; i ++ )
    {
    	int x, y;
    	std::cin >> x >> y;
    	add(x, y);
    	add(y, x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	if (res[i] == 0)
    		dfs(i);
    	ans = std::max(ans, res[i]);
    }
    std::cout << "Case #" << t << ": " << ans << "\n";
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    for (int i = 1; i <= t; i ++ )
        solve(i);
    return 0;
}

