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
int w[N], v[N];
LL f[100010];

void solve()
{
	memset(f, 0x3f, sizeof f);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> w[i] >> v[i];
    f[0] = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	for (int j = 100005; j >= v[i]; j -- )
    	{
    		f[j] = std::min(f[j], f[j - v[i]] + w[i]);
    	}	
    }

    LL ans = 0;
    for (int i = 1; i <= 100005; i ++ )
    {
    	if (f[i] <= m)
    		ans = i;
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