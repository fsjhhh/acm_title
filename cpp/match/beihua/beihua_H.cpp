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
    LL x, y;
    double k;
    std::cin >> x >> y;
    if (x > y)
        k = (x * 1.0) / (y * 1.0);
    else
        k = (y * 1.0) / (x * 1.0);
    /*int r = 0;
    int res = 0;
    for (int i = 1; i <= x; i++)
    {
        double t = k * i;
        int t1 = t;
        if (t1 == t)
        {
            res = res + (t - r);
        }
        else
        {
            res = res + (t - r + 1);
        }
        // std::cout << r << " " << t << std::endl;
        // res = res + (t - r + 1);
        r = t;
    }*/
    int r = k;
    if (k == r)
    {
        std::cout << std::max(x, y) << std::endl;
    }
    else
    {
        std::cout << x + y - std::__gcd(x, y) << std::endl;
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