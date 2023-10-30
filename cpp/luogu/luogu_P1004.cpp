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

const int N = 20;
int a[N][N];
int f[N][N][N][N];

void solve()
{
	int n;
	std::cin >> n;
    int x, y, s;
    while (1)
    {
    	std::cin >> x >> y >> s;
    	if (!x)
    		break;
    	a[x][y] = s;
    }
    for (int i = 1; i <= n; i ++ )
    	for (int j = 1; j <= n; j ++ )
    		for (int l = 1; l <= n; l ++ )
    			for (int k = 1; k <= n; k ++ )
    			{
    				f[i][j][l][k] = std::max(std::max(f[i - 1][j][l - 1][k], f[i][j - 1][l][k - 1]), 
    										 std::max(f[i - 1][j][l][k - 1], f[i][j - 1][l - 1][k])) + a[i][j];
    				if (i != l && j != k)
    					f[i][j][l][k] += a[l][k];    			
    			}
    std::cout << f[n][n][n][n] << "\n";
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

