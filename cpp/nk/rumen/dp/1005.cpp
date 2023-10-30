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

const int N = 110;
LL a[N][N], f[N][N], res[N];

void solve()
{
	int n, m;
	std::cin >> n >> m;

	memset(f, -0x3f, sizeof f);

	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			std::cin >> a[i][j];

	for (int i = 1; i <= m; i ++ )
		f[1][i] = a[1][i];

	for (int i = 2; i <= n; i ++ )
		for (int j = i; j <= m; j ++ )
			for (int k = 0; k < j; k ++ )
				f[i][j] = std::max(f[i - 1][k] + a[i][j], f[i][j]);

	res[n + 1] = m + 1;
	for (int i = n; i >= 1; i -- )
	{
		LL temp = -INF;
		for (int j = res[i + 1] - 1; j >= 1; j -- )
		{
			if (f[i][j] >= temp)
			{
				temp = f[i][j];
				res[i] = j;
			}
		}
		if (i == n)
			std::cout << temp << "\n";
	}
	
	for (int i = 1; i <= n; i ++ )
		std::cout << res[i] << " \n"[i == n];
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}
