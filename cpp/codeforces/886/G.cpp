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

void solve()
{
	LL ans = 0;
	std::map<int, LL> col, row, dg, udg;
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		LL x, y;
		std::cin >> x >> y;
		ans += col[x];
		col[x] ++ ;
		ans += row[y];
		row[y] ++ ;
		ans += dg[y - x];
		dg[y - x] ++ ;
		ans += udg[y + x];
		udg[y + x] ++ ;
	}
	std::cout << ans * 2 << "\n";
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}