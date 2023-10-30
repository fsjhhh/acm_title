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
#define IOS std::ios::sync_with_stdio(false); \
            std::cin.tie(0);              \
            std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 50;
int s[N * 8], g[5];
int f[N][N][N][N];

void solve()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		std::cin >> s[i];
	f[0][0][0][0] = s[1];
	for (int i = 1; i <= m; i ++ )
	{
		int x;
		std::cin >> x;
		g[x] ++ ;
	}

	for (int a = 0; a <= g[1]; a ++ )
	{
		for (int b = 0; b <= g[2]; b ++ )
		{
			for (int c = 0; c <= g[3]; c ++ )
			{
				for (int d = 0; d <= g[4]; d ++ )
				{
					int st = 1 + a + 2 * b + 3 * c + 4 * d;
					if (a) f[a][b][c][d] = std::max(f[a][b][c][d], f[a - 1][b][c][d] + s[st]);
					if (b) f[a][b][c][d] = std::max(f[a][b][c][d], f[a][b - 1][c][d] + s[st]);
					if (c) f[a][b][c][d] = std::max(f[a][b][c][d], f[a][b][c - 1][d] + s[st]);
					if (d) f[a][b][c][d] = std::max(f[a][b][c][d], f[a][b][c][d - 1] + s[st]);
				}
			}
		}
	}


	std::cout << f[g[1]][g[2]][g[3]][g[4]] << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
