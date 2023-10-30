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

const int N = 100010;
LL a, b, cnt;
bool st[N];

void solve()
{
    std::cin >> a >> b;
    if (a < b)
    	std::cout << 0 << "\n";
    else
    {
    	bool pd = false;
    	for (int i = 0; i <= 10; i ++ )
    	{
    		if ((b >> i & 1) != (a >> i & 1) && (b >> i & 1) == 1)
    		{
    			pd = true;
    			std::cout << 0 << "\n";
    			break;
    		}
            if ((b >> i & 1) != (a >> i & 1) && (b >> i & 1) == 0 && (a >> i & 1) == 1)
                cnt ++ ;
    	}
        if (!pd)
        {
            LL ans = 1;
            for (int i = 1; i <= cnt; i ++ )
                ans *= i;
            std::cout << ans << "\n";
        }
    }
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

