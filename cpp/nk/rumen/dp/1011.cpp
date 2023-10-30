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
int a[N];
int f[N], g[N], idx1, idx2;

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
    	std::cin >> a[i];
    	f[i] = g[i] = 1;
    }

    for (int i = 1; i <= n; i ++ )
    {
    	for (int j = 1; j <= i; j ++ )
    		if (a[i] > a[j])
    			f[i] = std::max(f[i], f[j] + 1);
    }

    for (int i = n; i >= 1; i -- )
    {
    	for (int j = n; j >= i; j -- )
    		if (a[i] > a[j])
                g[i] = std::max(g[i], g[j] + 1);
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++ )
    	ans = std::max(ans, f[i] + g[i] - 1);

    std::cout << n - ans << "\n";
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}
