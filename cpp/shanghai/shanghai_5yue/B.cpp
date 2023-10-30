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

void solve()
{
    LL m, x, a, b;
    scanf("%lld%lld%lld%lld", &m, &x, &a, &b);
    LL c_m = std::min(m / x, b);
    if (a + m - b * x < 0)
    {
        double ans = ((a + m) * 1.0) / ((a + m + b) * 1.0);
        printf("%0.9lf\n", ans);
    }
    else
    {
        double ans = ((a + m - c_m * x) * 1.0) / ((a + m + b - c_m * (x + 1)) * 1.0);
        printf("%0.9lf\n", ans);
    }
}

int main()
{
    IOS;
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}