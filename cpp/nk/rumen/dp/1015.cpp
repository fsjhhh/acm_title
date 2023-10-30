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

const int N = 310;
LL w[N][N], f[N][N];
LL n, m;

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
    	for (int j = 1; j <= m; j ++ )
    		std::cin >> w[i][j];
        std::sort(w[i] + 1, w[i] + m + 1);
        for (int j = 1; j <= m; j ++ )
            w[i][j] += w[i][j - 1];
    	for (int j = 1; j <= m; j ++ )
    		w[i][j] += j * j;
    }

    memset(f, 0x3f, sizeof f);

    f[0][0] = 0;
    for (int i = 1; i <= n; i ++ )
    	for (int j = i; j <= std::min(i * m, n); j ++ )
    		for (int k = 0; k <= std::min(i * m, n); k ++ )
    			f[i][j] = std::min(f[i][j], f[i - 1][k] + w[i][j - k]);

    LL res = INFL;
    for (int i = 1; i <= n; i ++ )
    	res = std::min(res, f[i][n]);

    std::cout << res << "\n";

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

