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
int h[N], e[2 * N], ne[2 * N], idx;
int w[N];
bool st[N], ans[N];
int n, m;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs()
{
	std::queue<int> q;
	q.push(1);
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = true;
		if (w[t] != -1)
		{
			ans[t] = true;
		}
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (!st[j])
			{
				w[j] = std::max(w[j], w[t] - 1);
				q.push(j);
			}
		}
	}
}

void solve()
{
	memset(h, -1, sizeof h);
	memset(w, -1, sizeof w);
    std::cin >> n >> m;
    for (int i = 2; i <= n; i ++ )
    {
    	int a;
    	std::cin >> a;
    	add(a, i);
    	add(i, a);
    }

    for (int i = 1; i <= m; i ++ )
    {
    	int x, y;
    	std::cin >> x >> y;
    	w[x] = std::max(w[x], y);
    }

    bfs();
    int res = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	if (ans[i])
    		res ++ ;
    }
    std::cout << res << "\n";

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

