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

const int N = 2e5 + 10;
LL a[N], b[N];

void solve()
{
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
    	int x;
    	std::cin >> x;
        if (x <= n)
    	   a[x] ++ ;
    }
    for (int i = 1; i <= n; i ++ )
    	for (int j = i; j <= n; j += i)
    		b[j] += a[i];
    LL ans = 0;
    for (int i = 1; i <= n; i ++ )
    	ans = std::max(ans, b[i]);
    std::cout << ans << "\n";
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}