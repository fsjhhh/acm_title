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

const int N = 1e4 + 10;
int h[N], e[2 * N], ne[2 * N], w[2 * N], idx; // 邻接表
int n, m, ans;
int res[N], sum[N], Root, siz; // 树的重心
bool st[N], pd[N];
int que[N];
int arr[N], b[N], d[N], tot; // 路径

bool cmp(int x, int y)
{
	return d[x] < d[y];
}

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
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
			res[u] = std::max(res[u], sum[j]);
		}
	}
	res[u] = std::max(res[u], siz - sum[u]);
	if (res[Root] > res[u])
		Root = u;
}

void dfs(int u, int W, int fa, int from)
{
	arr[++ tot] = u;
	d[u] = W;
	b[u] = from;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j != fa && !st[j])
			dfs(j, W + w[i], u, from);
	}
}

void calc(int u)
{	
	tot = 0;
	arr[++ tot] = u;
	d[u] = 0;
	b[u] = u;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			dfs(j, w[i], u, j);
		}
	}
	std::sort(arr + 1, arr + tot + 1, cmp);
	for (int i = 1; i <= m; i ++ )
	{
		int k = que[i];
		int l = 1, r = tot, ret = 0;
		if (pd[i])
			continue;
		while (l < r)
		{
			if (d[arr[l]] + d[arr[r]] > k)
				r -- ;
			else if (d[arr[l]] + d[arr[r]] < k)
				l ++ ;
			else if (b[arr[l]] == b[arr[r]])
			{
				if (d[arr[r]] == d[arr[r - 1]])
					r -- ;
				else
					l ++ ;
			}
			else
			{
				pd[i] = true;
				break;
			}
		}
	}
}

void DFS(int u)
{
	st[u] = true;
	calc(u);
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			Root = 0;
			siz = sum[j];
			GetRoot(j, 0);
			DFS(Root);
		}
	}
}

void solve()
{
	memset(h, -1,sizeof h);
	std::cin >> n >> m;
	for (int i = 1; i < n; i ++ )
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}
	for (int i = 1; i <= m; i ++ )
	{
		std::cin >> que[i];

	}
	Root = 0;
	res[Root] = INF;
	siz = n;
	GetRoot(1, 0);
	DFS(Root);
	for (int i = 1; i <= m; i ++ )
	{
		if (pd[i])
			std::cout << "AYE" << "\n";
		else
			std::cout << "NAY" << "\n";
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

// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <cmath>
// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <unordered_set>
// #include <queue>
// #include <deque>
// //priority_queue 优先队列
// #define IOS                           \
//     std::ios::sync_with_stdio(false); \
//     std::cin.tie(0);                  \
//     std::cout.tie(0);

// typedef long long LL;
// typedef std::pair<int, int> PII;
// typedef std::pair<LL, LL> PLL;
// const int INF = 0x3f3f3f3f;
// const LL INFL = 0x3f3f3f3f3f3f3f3f;

// const int N = 1e4 + 10;
// int h[N], e[2 * N], ne[2 * N], w[2 * N], idx;
// int res[N], sum[N], Root, siz, ans;
// int arr[N], tot;
// bool st[N];
// int n, m, k;

// void add(int a, int b, int x)
// {
// 	e[idx] = b, w[idx] = x, ne[idx] = h[a], h[a] = idx ++ ;
// }

// void GetRoot(int u, int fa)
// {
// 	res[u] = 0;
// 	sum[u] = 1;
// 	for (int i = h[u]; i != -1; i = ne[i])
// 	{
// 		int j = e[i];
// 		if (j != fa && !st[j])
// 		{
// 			GetRoot(j, u);
// 			sum[u] += sum[j];
// 			res[u] = std::max(res[u], sum[j]);
// 		}
// 	}
// 	res[u] = std::max(res[u], siz - sum[u]);
// 	if (res[Root] > res[u])
// 		Root = u;
// }

// void dfs(int u, int W, int fa)
// {
// 	arr[++ tot] = W;
// 	for (int i = h[u]; i != -1; i = ne[i])
// 	{
// 		int j = e[i];
// 		if (!st[j] && j != fa)
// 			dfs(j, W + w[i], u);
// 	}
// }

// int calc(int u, int W)
// {
// 	tot = 0;
// 	dfs(u, W, 0);
// 	std::sort(arr + 1, arr + tot + 1);
// 	int l = 1, r = tot, ret = 0;
// 	while (l < r)
// 	{
// 		if (arr[l] + arr[r] < k)
// 			l ++ ;
// 		else if (arr[l] + arr[r] > k)
// 			r -- ;
// 		else
// 		{
// 			if (arr[l] == arr[r])
// 			{
// 				ret += (r - l + 1) * (r - l) / 2;
// 				break;
// 			}
// 			else
// 			{
// 				int i = l, j = r;
// 				while (arr[i] == arr[l]) i ++ ;
// 				while (arr[j] == arr[r]) j -- ;
// 				ret += (i - l) * (r - j);
// 				l = i, r = j;
// 			}
// 		}
// 	}
// 	return ret;
// }

// void DFS(int u)
// {
// 	ans += calc(u, 0);
// 	st[u] = true;
// 	for (int i = h[u]; i != -1; i = ne[i])
// 	{
// 		int j = e[i];
// 		if (!st[j])
// 		{
// 			ans -= calc(j, w[i]);
// 			Root = 0;
// 			siz = sum[j];
// 			GetRoot(j, 0);
// 			DFS(Root);
// 		}
// 	}
// }

// void solve()
// {
// 	memset(h, -1, sizeof h);
// 	scanf("%d%d", &n, &m);
// 	for (int i = 1; i < n; i ++ )
// 	{
// 		int l, r, x;
// 		scanf("%d%d%d", &l, &r, &x);
// 		add(l, r, x);
// 		add(r, l, x);
// 	}
// 	for (int i = 1; i <= m; i ++ )
// 	{
// 		ans = 0;
// 		memset(st, 0, sizeof st);
// 		memset(res, 0, sizeof res);
// 		memset(sum, 0, sizeof sum);
// 		scanf("%d", &k);
// 		Root = 0;
// 		res[0] = INF;
// 		siz = n;
// 		GetRoot(1, 0);
// 		DFS(Root);
// 		if (ans)
// 			printf("AYE\n");
// 		else
// 			printf("NAY\n");
// 	}
// }

// int main()
// {
//     IOS;
//     int t = 1;
//     // std::cin >> t;
//     while (t -- )
//         solve();
//     return 0;
// }

