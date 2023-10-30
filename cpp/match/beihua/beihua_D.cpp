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
    double w, m, E, D, c0, d, p, c1, e;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &w, &m, &E, &D, &c0, &d, &p, &c1, &e);
    if (E >= (D + d))
    {
        double res1 = m, res2 = m;
        if (c0 <= m)
            res1 = res1 - c0 + w * (1.0 + p * 0.01);
        else
        {
            double r = c0 - m;
            double w1 = w - r;
            res1 = res1 - m + w1 * (1.0 + p * 0.01);
        }
        res2 = res2 + w;
        double res = std::max(res1, res2);
        printf("%0.2lf\n", res);
    }
    else
    {
        double res1 = m, res2 = m;
        LL x = 0;
        if (e != 0)
            x = (D + d - E + e - 1) / e;
        else
        {
            double res = m + w;
            printf("%0.2lf\n", res);
            return;
        }
        if (x * c1 + c0 <= m)
            res1 = res1 - x * c1 - c0 + w * (1.0 + p * 0.01);
        else
        {
            double r = x * c1 + c0 - m;
            double w1 = w - r;
            res1 = res1 - m + w1 * (1.0 + p * 0.01);
        }
        res2 = res2 + w;
        double res = std::max(res1, res2);
        printf("%0.2lf\n", res);
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