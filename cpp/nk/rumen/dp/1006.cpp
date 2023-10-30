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
LL a[N][N], f[N][N], pa[N][N];

void solve()
{
    LL w, h;
    std::cin >> w >> h;
    h -- ;
    LL maxx = -1;
    LL t, x, v, va;
    while (std::cin >> t >> x >> v >> va)
    {
    	if (h % v != 0)
    		continue;
    	a[t + h / v][x] += va;
    	maxx = std::max(maxx, t + h / v);
    }
    for (LL i = maxx; i >= 0; i -- )
    {
    	for (LL j = 1; j <= w; j ++ )
    	{
    		for (LL k = -2; k <= 2; k ++ )
    		{
    			if (j + k >= 1 && j + k <= w && f[i][j] < f[i + 1][j + k] + a[i][j])
    			{
    				f[i][j] = f[i + 1][j + k] + a[i][j];
    				pa[i][j] = k;
    			}
    		}
    	}
    }

    std::cout << f[0][w / 2 + 1] << "\n";
    LL s = w / 2 + 1;
    for (int i = 0; i < maxx; i ++ )
    {
    	std::cout << pa[i][s] << "\n";
    	s += pa[i][s]; 
    }
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}
