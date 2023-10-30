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
// priority_queue 优先队列
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
LL a[N];

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    LL f = 0, z = 0, fz = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
            f++;
        if (a[i] > 0)
        {
            z++;
            sum += a[i];
        }
    }
    if (f == 0)
    {
        LL ans = 0;
        for (int i = 2; i <= n; i++)
            ans += (a[i] * a[1]);
        std::cout << ans << std::endl;
    }
    else if (z == 0)
    {
        LL ans = 0;
        for (int i = 1; i < n; i++)
            ans += (a[i] * a[n]);
        std::cout << ans << std::endl;
    }
    else
    {
        LL ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < 0)
            {
                ans += (a[i] * sum);
            }
        }
        std::cout << ans << std::endl;
    }
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}