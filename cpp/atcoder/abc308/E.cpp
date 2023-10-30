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
int a[N];
char c[N];

LL MEX(int x, int y, int z)
{
	std::vector<int> b = {x, y, z};
	std::sort(b.begin(), b.end());
	if (b[0] != 0)
		return 0;
	if (b[1] != 1 && b[2] != 1)
		return 1;
	if (b[2] != 2)
		return 2;
	return 3;
}

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i];
    for (int i = 1; i <= n; i ++ )
    	std::cin >> c[i];
    std::map<LL, LL> m, x;
    LL ans = 0;
    for (int i = 1; i <= n; i ++ )
    	if (c[i] == 'X')
    		x[a[i]] ++ ;
    for (int i = 1; i <= n; i ++ )
    {
    	if (c[i] == 'M')
    		m[a[i]] ++ ;
    	else if (c[i] == 'E')
    	{
    		for (auto [u1, v1] : m)
    		{
    			for (auto [u2, v2] : x)
    			{
    				ans += (MEX(u1, a[i], u2) * (v1 * v2));
    			}
    		}
    	}
    	else
    		x[a[i]] -- ;
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

