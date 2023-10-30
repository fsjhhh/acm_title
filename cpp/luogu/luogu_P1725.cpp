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

const int N = 2e5 + 10;
int q[N], hh = 0, tt = -1;
int a[N], f[N];

void solve()
{
	int n, l, r;
	std::cin >> n >> l >> r;
	for (int i = 0; i <= n; i ++ )
		std::cin >> a[i];
	memset(f, -0x3f, sizeof f);
	f[0] = 0;
	int idx = 0;
	for (int i = l; i <= n; i ++ )
	{
		while (hh <= tt && f[q[tt]] <= f[idx])
			tt -- ;
		q[++ tt] = idx;
		while (q[hh] + r < i)
			hh ++ ;

		f[i] = f[q[hh]] + a[i];
		idx ++ ;
	}
	int ans = -INF;
	for (int i = n - r + 1; i <= n; i ++ )
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
