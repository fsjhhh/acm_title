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
int a[N], b[N];

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    int even = 0, odd = 0, o = INF;
    bool pd = false;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 0)
            even++;
        else
        {
            odd++;
            o = std::min(o, a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 0)
        {
            if (a[i] < o)
                pd = true;
        }
    }
    if (odd == 0 || even == 0)
        std::cout << "YES" << std::endl;
    else
    {
        if (pd)
            std::cout << "NO" << std::endl;
        else
            std::cout << "YES" << std::endl;
    }
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