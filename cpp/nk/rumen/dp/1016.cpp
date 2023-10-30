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

const int N = 10010, M = 110;
LL f[N][M], a[N];
LL n, m, k;

void solve()
{
	memset(f, -0x3f, sizeof f);
	std::cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++ )
		std::cin >> a[i];

	f[0][0] = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
		{
			f[i][j] = f[i - 1][j];
			if (j == 1)
				f[i][j] = std::max(f[i - 1][j], a[i]);
			if (i - k >= 0)
				f[i][j] = std::max(f[i][j], f[i - k][j - 1] + a[i]);
		}

	std::cout << f[n][m] << "\n";

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

