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

const int N = 110;
std::map<std::string, int> mp;
std::string c[N], d[N];

void solve()
{
    int n, m;
    LL p0 = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
    	std::cin >> c[i];
    }
    for (int i = 1; i <= m; i ++ )
    {
    	std::cin >> d[i];
    }
    for (int i = 0; i <= m; i ++ )
    {
    	int x;
    	std::cin >> x;
    	if (i == 0)
    		p0 = x;
    	else
    	{
    		mp[d[i]] = x;
    	}
    }

    LL ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	if (mp.count(c[i]))
    		ans += mp[c[i]];
    	else
    		ans += p0;
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

