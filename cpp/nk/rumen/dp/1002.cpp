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
#define IOS                           \
	std::ios::sync_with_stdio(false); \
	std::cin.tie(0);                  \
	std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10, mod = 1e9 + 7;
LL f[N][3];

void solve()
{
	std::memset(f, 0, sizeof f);
	f[0][0] = f[0][1] = f[0][2] = 0;
	f[1][0] = f[1][1] = f[1][2] = 1;
	f[2][0] = f[2][1] = f[2][2] = 3;
	for (int i = 3; i < N; i++)
	{
		f[i][0] = (f[i - 1][1] + f[i - 1][2] + f[i - 2][1] + f[i - 2][2]) % mod;
		f[i][1] = (f[i - 1][0] + f[i - 1][2] + f[i - 2][0] + f[i - 2][2]) % mod;
		f[i][2] = (f[i - 1][0] + f[i - 1][1] + f[i - 2][0] + f[i - 2][2]) % mod;
	}
	int t;
	std::cin >> t;
	while (t--)
	{
		int n;
		std::cin >> n;
		LL ans = (f[n][0] + f[n][1] + f[n][2]) % mod;
		std::cout << ans << std::endl;
	}
}

int main()
{
	IOS;
	int t = 1;
	while (t--)
		solve();

	return 0;
}
