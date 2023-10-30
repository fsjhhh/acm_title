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

const int N = 1e4 + 10;
int ti[N], col[N], row[N];
int n, m;
int f[N];

void solve()
{
	std::cin >> n >> m;
	for (int i = 1; i <= m; i ++ )
		std::cin >> ti[i] >> col[i] >> row[i];
	for (int i = 1; i <= m; i ++ )
		f[i] = 1;
	for (int i = 1; i <= m; i ++ )
	{
		for (int j = 1; j < i; j ++ )
		{
			int d = abs(col[i] - col[j]) + abs(row[i] - row[j]);
			int t = abs(ti[i] - ti[j]);
			if (d <= t)
				f[i] = std::max(f[i], f[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i ++ )
		ans = std::max(ans, f[i]);
	std::cout << ans << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
