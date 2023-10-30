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

const int mod = 998244353;

void solve()
{
    int n;
    std::cin >> n;
    LL ans = 0;
    LL c = 1;
    for (int i = 1; i <= n; i ++ )
    {
    	int x;
    	std::cin >> x;
    	if (x == 1)
    	{
    		ans = (ans + c) % mod;
    	}
    	c = (c * 2) % mod;
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

