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
LL a[N], b[N];
LL n, m, d;

void solve()
{
    std::cin >> n >> m >> d;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= m; i++)
        std::cin >> b[i];
    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + m + 1);
    LL ans = -1;
    for (int i = 1; i <= n; i++)
    {
        LL x = a[i] + d;
        int l = 1, r = m;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (b[mid] > x)
                r = mid - 1;
            else
                l = mid;
        }
        // std::cout << l << std::endl;
        // l = std::upper_bound(b, b + m, a[i] + d) - b - 1;
        if (l > 0 && abs(a[i] - b[l]) <= d && a[i] + b[l] > ans)
            ans = a[i] + b[l];
    }
    std::cout << ans << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}