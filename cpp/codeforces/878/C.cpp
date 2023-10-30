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

const int N = 2e5 + 10;
LL a[N];

void solve()
{
    LL n, k, q;
    std::cin >> n >> k>> q;
    LL res = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	std::cin >> a[i];
    }

    for (int i = 0, j = 1; i <= n; )
    {
        bool pd = false;
    	while (a[j] <= q && j <= n)
        {
            // pd = true;
    		j ++ ;
        }
        // std::cout << j << " " << i << "\n";
    	LL ans = j - i - 1;
        i = j ++ ;
        // std::cout << ans << "\n";
    	if (ans >= k)
    	{
    		LL t = ans - k + 1;
            // std::cout << t << "\n";
    		res += (t * (t + 1)) / 2;
    	}
    }
    std::cout << res << "\n";

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

