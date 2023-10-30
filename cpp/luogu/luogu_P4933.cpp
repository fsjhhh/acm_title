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

const int N = 1010, M = 2e4 + 10, mod = 998244353;
int f[N][M * 2];
int n, a[N];

void solve()
{
	std::cin >> n;
	for (int i = 1; i <= n; i ++ )
		std::cin >> a[i];
	LL ans = 0, p = 20000;
	for (int i = 1; i <= n; i ++ )
	{
		ans ++ ;
		for (int j = i - 1; j > 0; j -- )
		{
			f[i][a[i] - a[j] + p] = (f[i][a[i] - a[j] + p] + f[j][a[i] - a[j] + p] + 1) % mod;
			ans = (ans + f[j][a[i] - a[j] + p] + 1) % mod;
		}
	}

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
