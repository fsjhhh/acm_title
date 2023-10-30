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
double a[N];

void solve()
{
    double n, d, h;
    scanf("%lf%lf%lf", &n, &d, &h);
    for (int i = 1; i <= n; i ++ )
    	scanf("%lf", &a[i]);
    std::sort(a + 1, a + (int)n + 1);
    double ans = 0;
    double sq = (d * h * 1.0) / 2.0;
    for (int i = 1; i < n; i ++ )
    {
    	if (a[i + 1] - a[i] < h)
    	{
    		double l = (((h - (a[i + 1] - a[i]) * 1.0) / (h * 1.0)) * d * 1.0);
    		double s = (((d + l) * 1.0) * (a[i + 1] - a[i]) * 1.0) / 2.0;
    		ans += s;
    	}
    	else
    		ans += sq;
    }
    ans += sq;
    printf("%0.9lf\n", ans);

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

