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

const int mod = 998244353;

const int N = 1e6 + 10;
LL f[N][2];

void solve()
{
	LL n, m, ans = 1;
	std::cin >> n >> m;
	if (n <= 3)
	{
		for (int i = 1; i <= n; i ++ )
		{
			ans = (ans * (m - i + 1) % mod) % mod;
		}
		std::cout << ans << "\n";
	}
	else
	{
		f[1][0] = m;
		for (int i = 2; i <= n; i ++ )
		{
			f[i][0] = f[i - 1][1];
			f[i][1] = ((f[i - 1][0] * (m - 1) % mod) % mod + ((f[i - 1][1] * (m - 2) % mod) % mod)) % mod;
		}
		std::cout << f[n][1] % mod << "\n";
	}
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

