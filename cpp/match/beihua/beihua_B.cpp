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

const int N = 5e5 + 10;
LL a[N], b[N], sb[N];

void solve()
{
    int n, m;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::cin >> m;
    for (int i = 1; i <= m; i++)
        std::cin >> b[i];

    std::sort(b + 1, b + m + 1);
    for (int i = 1; i <= m; i++)
        sb[i] = sb[i - 1] + b[i];
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = m;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (b[mid] < a[i])
                l = mid + 1;
            else
                r = mid;
        }
        ans += sb[l - 1];
        ans += ((m - l + 1) * a[i]);
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