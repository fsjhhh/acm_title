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

LL n, k;
LL cnt = 0;
LL a[1010];
int c = 2;

void solve()
{
	std::cin >> n >> k;
	LL ans = 1, res = 1;
	for (int i = 0; i < k; i ++ )
	{
		if (i != 0)
		{
			res *= 2;
			ans += res;
		}
		// std::cout << i << " " << ans << "\n";
		if (ans >= n)
		{
			// std::cout << "n" << "\n";
			std::cout << n + 1 << "\n";
			return	 ;
		}
	}
	std::cout << ans + 1 << "\n";

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

