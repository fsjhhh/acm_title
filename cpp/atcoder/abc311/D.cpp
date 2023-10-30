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

struct node
{
	int x, y, d;
};

const int N = 210;
char mp[N][N];
bool st[N][N], st1[N][N];
int dist[N][N];
int ans = 0;

int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

void bfs(int x, int y)
{
	std::queue<node> q;
	q.push({x, y, -1});
	st[x][y] = true;
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		if (t.d == -1)
		{
			if (st1[t.x][t.y])
				continue;
			for (int i = 0; i < 4; i ++ )
			{
				int tx = t.x + dx[i], ty = t.y + dy[i];
				if (mp[tx][ty] == '#')
					continue;
				q.push({tx, ty, i});
				st[tx][ty] = true;
			}
			st1[t.x][t.y] = true;
		}
		else
		{
			int tx = t.x + dx[t.d], ty = t.y + dy[t.d];
			if (mp[tx][ty] == '#')
			{
				st[t.x][t.y] = true;
				q.push({t.x, t.y, -1});
			}
			else
			{
				q.push({tx, ty, t.d});
				st[tx][ty] = true;
			}
		}
	}

}

void solve()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    	for (int j = 1; j <= m; j ++ )
    		std::cin >> mp[i][j];

    bfs(2, 2);

    for (int i = 1; i <= n; i ++ )
    	for (int j = 1; j <= m; j ++ )
    		if (st[i][j])
    			ans ++ ;

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