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

const int N = 1e5 + 10;
LL a[N], sum;

void solve()
{
	LL n, p, x, q, y;
	std::cin >> n >> p >> x >> q >> y;
	for (int i = 1; i <= n; i ++ )
	{
		std::cin >> a[i];
		sum += a[i];
	}
    sum %= n;
	LL ans = INFL;
	if (sum == 0)
		ans = 0;
	else
	{
		for (int i = 0; i <= 10000005; i ++ )
		{
            if (sum <= i * y)
                ans = std::min(ans, ((i * y - sum) % n) * p + i * q);
            else
                ans = std::min(ans, (n - (sum - i * y) % n) * p + i * q);
		}
	}
	std::cout << ans << "\n";
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

