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

const int N = 1010, mod = 1e9 + 7;
char a[N][N];
LL f[N][N];

void solve()
{
	int n, m;
	std::cin >> n >> m;
    f[1][0] = 1;
    for (int i = 1; i <= n; i ++ )
    	for (int j = 1; j <= m; j ++ )
    		std::cin >> a[i][j];

    for (int i = 1; i <= n; i ++ )
    	for (int j = 1; j <= m; j ++ )
            if (a[i][j] == '.')
    		  f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;

    std::cout << f[n][m] << "\n";

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