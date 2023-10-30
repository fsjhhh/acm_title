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

const int N = 2e5 + 10, M = 1e9;
LL a[N], n, c;

bool check(LL x)
{
	LL ans = 0;
	LL t = c;
	for (int i = 1; i <= n; i ++ )
	{
		t -= ((2 * x + a[i]) * (2 * x + a[i]));
		if (t < 0)
			return false;
	}
	return true;
}

void solve()
{
 	std::cin >> n >> c;
 	for (int i = 1; i <= n; i ++ )
 		std::cin >> a[i];
 	LL l = 1, r = M;
 	while (l < r)
 	{
 		LL mid = (l + r + 1) >> 1;
 		if (check(mid))
 			l = mid;
 		else
 			r = mid - 1;
 	}
 	std::cout << l << "\n";
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