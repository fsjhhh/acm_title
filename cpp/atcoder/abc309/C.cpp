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

const int N = 5e5 + 10;
PLL a[N];

void solve()
{
    LL n, k;
    std::cin >> n >> k;
    LL sum = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	std::cin >> a[i].first >> a[i].second;
    	sum += a[i].second;
    }
    std::sort(a + 1, a + n + 1);
    LL cnt = 0, i = 1;
    if (sum <= k)
    {
    	std::cout << 1 << "\n";
    	return ;
    }
    for (int i = 1; i <= n; i ++ )
    {
        cnt = a[i].first + 1;
        sum -= a[i].second;
        if (sum <= k)
        {
            std::cout << cnt << "\n";
            return ;
        }
    }
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

