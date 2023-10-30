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

const int N = 3e5 + 10;
int f[N], g[N];
int m, s, T;

void solve()
{
	std::cin >> m >> s >> T;
	g[0] = m;
	for (int i = 1; i <= T; i ++ )
	{
		if (g[i - 1] >= 10)
		{
			f[i] = f[i - 1] + 60;
			g[i] = g[i - 1] - 10;
		}
		else
		{
			f[i] = f[i - 1];
			g[i] = g[i - 1] + 4;
		}
	}
	for (int i = 1; i <= T; i ++ )
	{
		if (f[i] < f[i - 1] + 17)
			f[i] = f[i - 1] + 17;
		if (f[i] >= s)
		{
			std::cout << "Yes" << std::endl;
			std::cout << i << std::endl;
			return ;
		}
	}
	std::cout << "No" << std::endl;
	std::cout << f[T] << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
