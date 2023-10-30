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

const int N = 110, mod = 1e6 + 7;
int a[N], f[N];

void solve()
{
	int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
    	for (int j = m; j >= 0; j -- )
    	{
    		for (int k = 1; k <= std::min(a[i], j); k ++ )
    		{
    			f[j] = (f[j] + f[j - k]) % mod; 
    		}
    	}
    }

    std::cout << f[m] << "\n";
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

