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

void solve()
{
    // double n, k, d;
    // scanf("%lf%lf%lf", &n, &k, &d);
    // double l = (n * 2.0) / (2 * k - 2 + sqrt(2));
    // l = (sqrt(2) * l) / 4;
    // double ans = (d * 1.0) / (l * l * 1.0);
    // printf("%0.10lf\n", ans);
    int n, d, k;
    scanf("%d%d%d", &n, &k, &d);
    double i = (double)(2 * n) / (2 * k - 2 + sqrt(2));
    double mx = ((d / pow(i * sqrt(2) / 4, 2)));
    printf("%0.10lf\n", mx);
}

int main()
{
    IOS;
    int t = 1;
    scanf("%d", &t);
    while (t -- )
        solve();
    return 0;
}