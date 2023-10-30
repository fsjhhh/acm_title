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

const int N = 310;
int a[N], b[N];

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ )
		std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	int l = 1, r = n;
	int idx = 0;
	while (l <= r)
	{
		if (l == r)
			b[++ idx ] = a[l];
		else
		{
			b[++ idx] = a[r];
			b[++ idx] = a[l];
		}
		l ++ ;
		r -- ;
	}

	LL ans = 0;
	for (int i = 1; i <= n; i ++ )
	{
		ans += (b[i] - b[i - 1]) * (b[i] - b[i - 1]);
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
