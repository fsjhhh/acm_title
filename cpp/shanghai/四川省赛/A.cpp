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

const int N = 1e5 + 10;
LL a[N];
double ans[N];

bool cmp1(LL a, LL b)
{
	return a > b;
}

bool cmp2(double a, double b)
{
	return a > b;
}

void solve()
{
    LL n, res = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i ++ )
    {
    	scanf("%lld", &a[i]);
    	res += a[i];
    }
    std::sort(a + 1, a + n + 1, cmp1);
    LL cnt = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	cnt += a[i];
    	double y = (cnt * 1.0) / (res * 1.0) * 100.0;
    	double x = (i * 1.0) / (n * 1.0) * 100.0;
    	ans[i] = y - x;
    }
    std::sort(ans + 1, ans + n + 1, cmp2);
    // double r = ans[1] * 100.0;
    printf("%0.9lf\n", ans[1]);
}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}