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

const int N = 510;
char a[N][N];
bool st[N][N];
int n, m;

char c[] = {'s', 'n', 'u', 'k', 'e'};
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

void bfs()
{
	std::queue<std::pair<int, std::pair<int, int>>> q;
	if (a[1][1] == c[0])
		q.push({0, {1, 1}});
	st[1][1] = true;
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		int d = t.first;
		int x = t.second.first, y = t.second.second;
		if (x == n && y == m)
		{
			std::cout << "Yes" << "\n";
			return ;
		}
		for (int i = 0; i < 4; i ++ )
		{
			int tx = x + dx[i], ty = y + dy[i];
			int td = (d + 1) % 5;
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && !st[tx][ty] && c[td] == a[tx][ty])
			{
				st[tx][ty] = true;
				q.push({td, {tx, ty}});
			}
		}
	}
	std::cout << "No" << "\n";
	
}

void solve()
{
    std::cin >> n >> m;
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

