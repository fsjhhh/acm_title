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

const int N = 310;
int a[N][N];
bool st[N][N];
int n, m;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

struct que
{
	int x, y;
	LL h;
	bool operator<(const que other) const
	{
		return h > other.h;
	}
};

void bfs()
{
	std::priority_queue<que> q;
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= m; j ++ )
		{
			if (i == 1 || j == 1 || i == n || j == m)
			{
				st[i][j] = true;
				q.push({i, j, a[i][j]});
			}
		}
	}
	LL ans = 0;
	while (q.size())
	{
		que t = q.top();
		q.pop();
		int x = t.x, y = t.y;
		LL h = t.h;
		st[x][y] = true;
		for (int i = 0; i < 4; i ++ )
		{
			int tx = x + dx[i], ty = y + dy[i];
			if (tx <= 1 || tx >= n || ty <= 1 || ty >= m || st[tx][ty])
				continue;
			st[tx][ty] = true;
			if (a[tx][ty] < h)
			{
				ans += (h - a[tx][ty]);
				q.push({tx, ty, h});
			}
			else
			{
				q.push({tx, ty, a[tx][ty]});
			}
		}
	}
	std::cout << ans << '\n';
}

void solve()
{
    std::cin >> m >> n;
    for (int i = 1; i <= n; i ++ )
    	for (int j = 1; j <= m; j ++ )
    		std::cin >> a[i][j];
    bfs();
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

