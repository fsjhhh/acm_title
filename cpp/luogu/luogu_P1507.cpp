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
int f[N][N];
int h[N], t1[N], k1[N];
int n, H, T;

void solve()
{
    std::cin >> H >> T >> n;
    for (int i = 1; i <= n; i ++ )
    {
    	std::cin >> h[i] >> t1[i] >> k1[i];
    }

    for (int i = 1; i <= n; i ++ )
    	for (int j = H; j >= h[i]; j -- )
    		for (int k = T; k >= t1[i]; k -- )
    			f[j][k] = std::max(f[j][k], f[j - h[i]][k - t1[i]] + k1[i]);

    std::cout << f[H][T] << "\n";
    		
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

