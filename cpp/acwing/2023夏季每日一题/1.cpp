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
    LL n, t, ans = 0;
    std::cin >> n >> t;
    LL ls = 0, s = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	LL d, b;
    	std::cin >> d >> b;
		if (d - ls >= s)
        {
            ans += s;
            s = b;
        }
        else
        {
            ans += (d - ls);
            s -= (d - ls);
            s += b;
        }
        ls = d;
    }
    if ((t - ls + 1) <= s)
        ans += (t - ls + 1);
    else
        ans += s;
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

