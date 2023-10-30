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

const int N = 110;
int h[N], e[2 * N], ne[2 * N], idx;
LL n, a[N], ans = INFL, w[N];
bool st[N];

void add(int x, int y)
{
	e[idx] = y, ne[idx] = h[x], h[x] = idx ++ ;
}

LL bfs(int u)
{
	memset(st, 0, sizeof st);
	memset(w, 0, sizeof w);
	std::queue<int> q;
	q.push(u);
	st[u] = true;
	LL res = 0;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (!st[j])
			{
				w[j] = w[t] + 1;
				st[j] = true;
				q.push(j);
			}
		}
	}

	for (int i = 1; i <= n; i ++ )
		res += (a[i] * w[i]);
	return res;

}

void solve()
{
	memset(h, -1, sizeof h);
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
    	int b, c;
    	std::cin >> a[i] >> b >> c;
    	if (b)
    	{
    		add(i, b);
    		add(b, i);
    	}
    	if (c)
    	{
    		add(i, c);
    		add(c, i);
    	}
    }

    for (int i = 1; i <= n; i ++ )
    {
    	LL res = bfs(i);
    	ans = std::min(res, ans);
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