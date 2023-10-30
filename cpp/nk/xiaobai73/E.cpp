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
int a[N];
int a_2[N], a_5[N];
int n, m;

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a_2[i] = a_5[i] = 0;
        int x = a[i], y = a[i];
        while (x % 2 == 0 && x)
        {
            x /= 2;
            a_2[i]++;
        }
        while (y % 5 == 0 && y)
        {
            y /= 5;
            a_5[i]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        a_2[i] = a_2[i - 1] + a_2[i];
        a_5[i] = a_5[i - 1] + a_5[i];
    }
    LL ans = 0;
    a_2[n + 1] = a_5[n + 1] = INF;
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = n + 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (std::min(a_2[mid] - a_2[i - 1], a_5[mid] - a_5[i - 1]) < m)
                l = mid + 1;
            else
                r = mid;
        }
        int x = l;
        l = i, r = n + 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (std::min(a_2[mid] - a_2[i - 1], a_5[mid] - a_5[i - 1]) < m + 1)
                l = mid + 1;
            else
                r = mid;
        }
        int y = l;
        if (y > x)
            ans += (y - x);
    }
    std::cout << ans << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}