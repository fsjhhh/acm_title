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
	int q, idx = 0;
    std::cin >> q;
    bool pd = false;
    std::vector<int> a(q + 1), ans(q + 1);
    for (int i = 1; i <= q; i ++ )
    {
    	int x;
    	std::cin >> x;
    	if (i == 1)
    	{
    		a[++ idx] = x;
    		ans[i] = 1;
    	}
    	else
    	{
    		if (!pd)
            {
                if (x >= a[idx])
                {
                    a[++ idx ] = x;
                    ans[i] = 1;
                }
                else
                {
                    if (x <= a[1])
                    {
                        pd = true;
                        a[++ idx ] = x;
                        ans[i] = 1;
                    }
                    else
                        ans[i] = 0;
                }
            }
            else
            {
                if (x <= a[1] && x >= a[idx])
                {
                    a[++ idx ] = x;
                    ans[i] = 1;
                }
                else
                    ans[i] = 0;
            }
    	}
    }
    for (int i = 1; i <= q; i ++ )
    	std::cout << ans[i];
    std::cout << "\n";
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

