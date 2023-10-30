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
#include <bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false); \
            std::cin.tie(0);              \
            std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 2010;
int f[N][N];
std::string a, b;

void solve()
{
	std::cin >> a >> b;
	int n = a.size(), m = b.size();
	for (int i = 0; i <= n; i ++ )
		f[i][0] = i;
	for (int i = 0; i <= m; i ++ )
		f[0][i] = i;
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= m; j ++ )
		{
			if (a[i - 1] == b[j - 1])
			{
				f[i][j] = f[i - 1][j - 1];
				continue;
			}
			f[i][j] = std::min(std::min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
		}
	}
	std::cout << f[n][m] << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
