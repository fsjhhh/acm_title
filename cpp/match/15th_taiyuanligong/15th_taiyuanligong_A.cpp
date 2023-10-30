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

int n, m, k;

void solve()
{
	std::cin >> n >> m >> k;

	if (n == 0)
	{
		if (m == 0 && k == 0)
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
		return ;
	}
	if (m == 0)
	{
		if (k == 0)
		{
			std::cout << "YES" << std::endl;
			for (int i = 1; i <= n; i ++ )
				std::cout << 0;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
		return ;
	}
	if (k == 0)
	{
		if (m != 0)
			std::cout << "NO" << std::endl;
		else
		{
			std::cout << "YES" << std::endl;
			for (int i = 1; i <= n; i ++ )
				std::cout << 0;
		}
		return ;
	}
	int c = m / k;
	int t = m % k;
	if (c == 0)
	{
		std::cout << "NO" << std::endl;
		return ;
	}
	int tt;
	if (t == 0)
		tt = m + c - 1;
	else
		tt = m + c;
	if (tt > n)
	{
		std::cout << "NO" << std::endl;
		return ;
	}
	if (tt <= n)
	{
		std::cout << "YES" << std::endl;
		for (int i = 1; i <= c; i ++ )
		{
			for (int j = 1; j <= k; j ++ )
				std::cout << 1;
			if (i != c)
				std::cout << 0;
		}
		if (t)
			std::cout << 0;
		for (int i = 1; i <= t; i ++ )
			std::cout << 1;
		for (int i = 1; i <= n - tt; i ++ )
			std::cout << 0;
	}
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
