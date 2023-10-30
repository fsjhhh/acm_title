#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
//#include <unordered_map>
#include <set>
//#include <unordered_set>
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

const int N = 30;
char s[N][N];
bool pd;

bool check(int u, int x, int y)
{
	for (int i = 1; i <= 9; i ++ )
	{
		if (s[x][i] == u + '0')
			return false;
		if (s[i][y] == u + '0')
			return false;
	}
	int tx = (x - 1) - (x - 1) % 3 + 1, ty = (y - 1) - (y - 1) % 3 + 1;
	for (int i = tx; i <= tx + 2; i ++ )
		for (int j = ty; j <= ty + 2; j ++ )
			if (s[i][j] == u + '0')
				return false;
	return true;
}

void dfs(int x, int y)
{
	if (pd || x == 10)
	{
		pd = true;
		return ;
	}
	while (s[x][y] != '0')
	{
		if (y == 9)
		{
			x ++ ;
			y = 0;
		}
		else
			y ++ ;
		if (x == 10)
		{
			pd = true;
			return ;
		}
	}
	for (int i = 1; i <= 9; i ++ )
	{
		if (check(i, x, y))
		{
			s[x][y] = i + '0';
			dfs(x, y);
			if (pd)
				return ;
			s[x][y] = '0';
		}
	}
	return ;
}

void solve()
{
    for (int i = 1; i <= 9; i ++ )
    	for (int j = 1; j <= 9; j ++ )
    		std::cin >> s[i][j];

    pd = false;
    dfs(1, 1);

    for (int i = 1; i <= 9; i ++ )
    {
    	for (int j = 1; j <= 9; j ++ )
    		std::cout << s[i][j];
    	std::cout << "\n";
    }
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

