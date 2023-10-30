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
LL a[N], b[N], c[N], idx = 0;

void solve()
{
    int n;
    std::cin >> n;
    idx = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	std::cin >> a[i];
    	a[i] %= n;
    }
    for (int i = 1; i <= n; i ++ )
    {
    	std::cin >> b[i];
    	b[i] %= n;
    }
    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + n + 1);
    int l = 1, r = n;
    LL ans = 0;
    for (l = 1; l <= n; l ++, r -- )
    {
        while (r > 0 && b[l] + a[r] >= n)
        {
            c[++ idx ] = a[r -- ];
        }
        if (r == 0)
            break;
        ans = ans + b[l] + a[r];
    }
    for (int i = 1; l <= n && i <= idx; l ++, i ++ )
    {
        ans = ans + (b[l] + c[i]) % n;
    }
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

