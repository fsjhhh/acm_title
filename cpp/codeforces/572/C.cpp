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

const int N = 1010;
const LL mod = 998244353;
LL a[N], f[N][N], g[N][N], res[100010];

void solve()
{
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    a[0] = -INFL;
    LL ans = 0;
    for (int u = 1; u * (k - 1) <= a[n]; u ++ )
    {
    	f[0][0] = 1;
    	int now = 0;
    	g[0][0] = 1;
    	for (int i = 1; i <= n; i ++ )
    	{
    		while (a[now] <= a[i] - u)
    			now ++ ;
    		for (int j = 0; j <= k; j ++ )
    		{
    			if (j)
    				f[i][j] = g[now - 1][j - 1];
    			g[i][j] = (g[i - 1][j] + f[i][j]) % mod;
    		}
    		res[u] = (res[u] + f[i][k]) % mod;
    	}
        ans = (res[u] + ans) % mod;
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

