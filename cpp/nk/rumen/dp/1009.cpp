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

const int N = 50;
LL f[N][N];

void solve()
{
    int n, m;
    std::cin >> n >> m;
    f[1][0] = 1;
    for (int i = 1; i <= m; i ++ )
    {
    	for (int j = 1; j <= n; j ++ )
    	{
    		if (j == 1)
    			f[j][i] = f[n][i - 1] + f[j + 1][i - 1];
    		else if (j == n)
    			f[j][i] = f[1][i - 1] + f[j - 1][i - 1];
    		else
    			f[j][i] = f[j - 1][i - 1] + f[j + 1][i - 1];
    	}
    }
    std::cout << f[1][m] << "\n";
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}
