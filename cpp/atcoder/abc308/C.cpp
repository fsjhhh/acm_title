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
const double b = 0.0000000000000001;
std::pair<PLL, LL> a[N];

bool cmp(std::pair<PLL, LL> x, std::pair<PLL, LL> y)
{
	if (x.first.first * y.first.second == x.first.second * y.first.first)
        return x.second < y.second;
    return x.first.first * y.first.second > x.first.second * y.first.first;
}

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
    {
    	LL x, y;
    	scanf("%lld%lld", &x, &y);
    	a[i] = {{x, x + y}, i};
    }
    std::sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i ++ )
    {
    	std::cout << a[i].second << " \n"[i == n];
    }

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

