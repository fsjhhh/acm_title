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

const int N = 50;
char s[N][N];
PII start, end;
bool st[N][N];
int dist[N][N];
int n, m, ans1, ans2, ans;
bool pd;
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};

bool check(int x, int y)
{
	if (x <= n && x > 0 && y <= m && y > 0 && st[x][y] == false && s[x][y] != '#')
		return true;
	else
		return false;
}

void dfs1(int x, int y, int dist, int fa)
{
	if (pd)
		return ;
	if (x == end.first && y == end.second)
	{
		ans1 = dist;
		pd = true;
		return ;
	}
	if (fa == 1)
	{

		if (check(x + 1, y))
			dfs1(x + 1, y, dist + 1, 4);
		if (check(x, y - 1))
			dfs1(x, y - 1, dist + 1, 1);
		if (check(x - 1, y))
			dfs1(x - 1, y, dist + 1, 2);
		if (check(x, y + 1))
			dfs1(x, y + 1, dist + 1, 3);
	}
	if (fa == 2)
	{
		if (check(x, y - 1))
			dfs1(x, y - 1, dist + 1, 1);
		if (check(x - 1, y))
			dfs1(x - 1, y, dist + 1, 2);
		if (check(x, y + 1))
			dfs1(x, y + 1, dist + 1, 3);
		if (check(x + 1, y))
			dfs1(x + 1, y, dist + 1, 4);
	}
	if (fa == 3)
	{
		if (check(x - 1, y))
			dfs1(x - 1, y, dist + 1, 2);
		if (check(x, y + 1))
			dfs1(x, y + 1, dist + 1, 3);
		if (check(x + 1, y))
			dfs1(x + 1, y, dist + 1, 4);
		if (check(x, y - 1))
			dfs1(x, y - 1, dist + 1, 1);
	}
	if (fa == 4)
	{
		if (check(x, y + 1))
			dfs1(x, y + 1, dist + 1, 3);
		if (check(x + 1, y))
			dfs1(x + 1, y, dist + 1, 4);
		if (check(x, y - 1))
			dfs1(x, y - 1, dist + 1, 1);
		if (check(x - 1, y))
			dfs1(x - 1, y, dist + 1, 2);
	}
}

void dfs2(int x, int y, int dist, int fa)
{
	if (pd)
		return ;
	if (x == end.first && y == end.second)
	{
		ans2 = dist;
		pd = true;
		return ;
	}
	if (fa == 1)
	{
		if (check(x - 1, y))
			dfs2(x - 1, y, dist + 1, 2);
		if (check(x, y - 1))
			dfs2(x, y - 1, dist + 1, 1);
		if (check(x + 1, y))
			dfs2(x + 1, y, dist + 1, 4);
		if (check(x, y + 1))
			dfs2(x, y + 1, dist + 1, 3);
	}
	if (fa == 2)
	{
		if (check(x, y + 1))
			dfs2(x, y + 1, dist + 1, 3);
		if (check(x - 1, y))
			dfs2(x - 1, y, dist + 1, 2);
		if (check(x, y - 1))
			dfs2(x, y - 1, dist + 1, 1);
		if (check(x + 1, y))
			dfs2(x + 1, y, dist + 1, 4);
	}
	if (fa == 3)
	{
		if (check(x + 1, y))
			dfs2(x + 1, y, dist + 1, 4);
		if (check(x, y + 1))
			dfs2(x, y + 1, dist + 1, 3);
		if (check(x - 1, y))
			dfs2(x - 1, y, dist + 1, 2);
		if (check(x, y - 1))
			dfs2(x, y - 1, dist + 1, 1);
	}
	if (fa == 4)
	{
		if (check(x, y - 1))
			dfs2(x, y - 1, dist + 1, 1);
		if (check(x + 1, y))
			dfs2(x + 1, y, dist + 1, 4);
		if (check(x, y + 1))
			dfs2(x, y + 1, dist + 1, 3);
		if (check(x - 1, y))
			dfs2(x - 1, y, dist + 1, 2);
	}
}

int bfs()
{
	std::queue<PII> q;
	q.push(start);
	dist[start.first][start.second] = 1;
	st[start.first][start.second] = true;
	while (q.size())
	{
		PII t = q.front();
		q.pop();
		int x = t.first, y = t.second;
		if (x == end.first && y == end.second)
			return dist[x][y];
		for (int i = 0; i < 4; i ++ )
		{
			int tx = x + dx[i], ty = y + dy[i];
			if (check(tx, ty))
			{
				
				dist[tx][ty] = dist[x][y] + 1;
				st[tx][ty] = true;
				q.push({tx, ty});
			}
		}
	}
	return 0;
}

void solve()
{
	memset(st, 0, sizeof st); 
	std::cin >> m >> n;
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= m; j ++ )
		{
			std::cin >> s[i][j];
			if (s[i][j] == 'S')
				start = {i, j};
			if (s[i][j] == 'E')
				end = {i, j};
		}
	}
	ans1 = ans2 = ans = 0;
	pd = false; 
	dfs1(start.first, start.second, 1, 1);
	pd = false;
	dfs2(start.first, start.second, 1, 1);
	ans = bfs();
	std::cout << ans1 << " " << ans2 << " " << ans << "\n";

}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

