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

const int N = 510;
LL f[N][N], a[N];

void solve()
{
    int n, d;
    std::cin >> n >> d;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i];
    for (int i = 2; i <= n; i ++ )
    {
    	for (int j = 1; j < i; j ++ )
    	{
    		LL w = (a[i] - a[j]) * (a[i] - a[j]);
    		LL c = i - j - 1;
    		for (int k = c; k <= d; k ++ )
    			f[i][k] = std::max(f[i][k], f[j][k - c] + w); 
    	}
    }
    std::cout << f[n][d] << "\n";
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