#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
// #include <unordered_map>
#include <set>
// #include <unordered_set>
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

const int N = 1e4 + 10;
int h[N], e[N * 2], ne[2 * N], w[2 * N], idx;
int Root, res[N], ans, sum[N];
int arr[N], idx1;
bool st[N];
int n, m, siz;

void add(int a, int b, int x)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = x, h[a] = idx ++ ;
}

void GetRoot(int u, int fa)
{
	res[u] = 0;
	sum[u] = 1;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j != fa && !st[j])
		{
			GetRoot(j, u);
			sum[u] += sum[j];
			res[u] = std::max(sum[j], res[u]);
		}
	}	
	res[u] = std::max(res[u], siz - sum[u]);
	if (res[Root] > res[u])
		Root = u;
}

void dfs(int u, int W, int fa)
{
	arr[++ idx1] = W;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j != fa && !st[j])
			dfs(j, W + w[i], u);
	}
}

int calc(int u, int W)
{
	idx1 = 0;
	dfs(u, W, 0);
	int l = 1, r = idx1, ret = 0;
	std::sort(arr + 1, arr + idx1 + 1);
	for ( ; ; l ++ )
	{
		while (r && arr[l] + arr[r] > m)
			r -- ;
		if (r < l)
			break;
		ret += (r - l);
	}
	// while (l <= r)
	// {
	// 	if (arr[l] + arr[r] <= m)
	// 	{
	// 		ret += r - l;
	// 		l ++ ;
	// 	}
	// 	else
	// 		r -- ;
	// }
	return ret;
}

void DFS(int u)
{
	ans += calc(u, 0);
	st[u] = true;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			ans -= calc(j, w[i]);
			Root = 0;
			siz = sum[j];
			GetRoot(j, 0);
			DFS(Root);
		}
	}
}

void solve()
{
    while (1)
    {	
    	std::cin >> n >> m;
    	if (!n && !m)
    		break;
    	idx = 0, idx1 = 0, ans = 0;
    	memset(h, -1, sizeof h);
    	memset(st, 0, sizeof st);
    	for (int i = 1; i < n; i ++ )
    	{
    		int l, r, x;
    		std::cin >> l >> r >> x;
    		add(l, r, x);
    		add(r, l, x);
    	}
    	Root = 0;
    	res[Root] = INF;
    	siz = n;
    	GetRoot(1, 0);
    	DFS(Root);
    	std::cout << ans << "\n";
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

