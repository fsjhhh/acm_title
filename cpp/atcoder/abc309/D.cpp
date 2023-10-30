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

bool st[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs(int x)
{
	int maxx = 0;
	std::queue<PII> q;
	q.push({0, x});
	st[x] = true;
	while (q.size())
	{
		PII t = q.front();
		q.pop();
		int dist = t.first, u = t.second;
		for (int i = h[u]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (!st[j])
			{
				st[j] = true;
				q.push({dist + 1, j});
				maxx = std::max(dist + 1, maxx);
			}
		}
	}
	return maxx;
}

void solve()
{
	memset(h, -1, sizeof h);
    int n1, n2, m;
    std::cin >> n1 >> n2 >> m;
    for (int i = 1; i <= m; i ++ )
    {
    	int a, b;
    	std::cin >> a >> b;
    	add(a, b);
    	add(b, a);
    }
    int ans1 = bfs(1);
    int ans2 = bfs(n1 + n2);
    std::cout << ans1 + ans2 + 1 << "\n";
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

