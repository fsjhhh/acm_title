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

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int f[N];
bool st[N];
int n, m;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u)
{
	if (h[u] == -1)
		return 0;
	if (st[u])
		return f[u];
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		f[j] = dfs(j);
		st[j] = true;
		f[u] = std::max(f[u], f[j] + 1);
	}
	return f[u];
}

void solve()
{
	memset(h, -1, sizeof h);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
    	int u, v;
    	std::cin >> u >> v;
    	add(u, v);
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	ans = std::max(ans, dfs(i));
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