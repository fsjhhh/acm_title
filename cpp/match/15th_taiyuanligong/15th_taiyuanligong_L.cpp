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
int n;
int a[N], f[N];

void solve()
{
	std::cin >> n;
	for (int i = 1; i <= 3 * n; i ++ )
		std::cin >> a[i];
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	f[1] = a[1];
	f[2] = a[2];
	for (int i = 3; i <= 3 * n; i ++ )
	{
		for (int j = 1; j <= 3; j ++ )
		{
			f[i] = std::min(f[i], f[i - j] + a[i]);
		}
	}
	int res = INF;
	for (int i = 3 * (n - 1) + 1; i <= 3 * n; i ++ )
	{
		res = std::min(res, f[i]);
	}
	std::cout << res << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
