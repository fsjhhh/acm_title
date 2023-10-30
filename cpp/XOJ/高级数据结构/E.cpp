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

const int N = 5e4 + 10;
int h[N], e[2 * N], ne[2 * N], idx;
bool st[N];
int ans = INF, n;
int v[N], idx1 = 0;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u)
{
	int res = 0;
	st[u] = true;
	int sum = 1;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			int s = dfs(j);
			res = std::max(res, s);
			sum += s;
		}
	}
	res = std::max(res, n - sum);
	if (ans > res)
	{
		ans = res;
		idx1 = 0;
		v[idx1 ++ ] = u;
	}
	else if (ans == res)
	{
		v[idx1 ++ ] = u;
	}
	return sum;
}

void solve()
{
	memset(h, -1, sizeof h);
    scanf("%d", &n);
    for (int i = 1; i < n; i ++ )
    {
    	int a, b;
    	scanf("%d%d", &a, &b);
    	add(a, b);
    	add(b, a);
    }
    dfs(1);
    std::sort(v, v + idx1);
    for (int i = 0; i < idx1; i ++ )
    	printf("%d ", v[i]);
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

