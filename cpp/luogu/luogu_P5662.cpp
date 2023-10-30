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
int f[10010], p[N][N];

void solve()
{
    int t, n, m;
    std::cin >> t >> n >> m;
    for (int i = 1; i <= t; i ++ )
    	for (int j = 1; j <= n; j ++ )
    		std::cin >> p[i][j];

    int ans = m;
    for (int i = 1; i < t; i ++ )
    {
    	memset(f, 0, sizeof f);
    	f[ans] = ans;
    	for (int j = 1; j <= n; j ++ )
    		for (int k = ans; k >= p[i][j]; k -- )
    			f[k - p[i][j]] = std::max(f[k - p[i][j]], f[k] + p[i + 1][j] - p[i][j]);

    	int mx = 0;
    	for (int j = 0; j <= ans; j ++ )
    		mx = std::max(mx, f[j]);
    	ans = mx;
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

