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

const int N = 3010;
bool st[N][N];
LL d[N][N];
int col[N], r;

void solve()
{
    int h, w, n;
    std::cin >> h >> w >> n;
    for (int i = 1; i <= h; i ++ )
        for (int j = 1; j <= w; j ++ )
            d[i][j] = 1;
    for (int i = 1; i <= n; i ++ )
    {
    	int x, y;
    	std::cin >> x >> y;
    	d[x][y] = 0;                                                                                           
    }
    for (int i = 1; i <= h; i ++ )
    {
    	for (int j = 1; j <= w; j ++ )  
    	{
            if (d[i][j])
                d[i][j] = std::min(d[i - 1][j - 1], std::min(d[i][j - 1], d[i - 1][j])) + 1;
    	}                
    }
    LL ans = 0;
    for (int i = 1; i <= h; i ++ )
    	for (int j = 1; j <= w; j ++ )
        {
            // std::cout << d[i][j] << " \n"[j == w];
    		ans += d[i][j];
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