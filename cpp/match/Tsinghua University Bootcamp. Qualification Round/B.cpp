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

const int N = 1e6 + 10;
LL a[N], sum[N];
PLL b[N];

bool cmp(PLL x, PLL y)
{
	if (x.second == y.second)
		return x.first > y.first;
	return x.second > y.second;
}

void solve()
{
    LL  n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++ )
    {
    	std::cin >> a[i];
    }
    while (m -- )
    {
    	int l, r;
    	std::cin >> l >> r;
    	sum[l] ++ ;
    	sum[r + 1] -- ;
    }
    for (int i = 1; i <= n; i ++ )
    {
    	sum[i] += sum[i - 1];
    	b[i] = {a[i], sum[i]};
 	}

 	sort(b + 1, b + n + 1, cmp);

 	for (int i = 1; i <= n; i ++ )
 	{
 		if (k >= b[i].first)
 		{
 			k -= b[i].first;
 			b[i].first = 0;
 		}
 		else
 		{
 			b[i].first -= k;
 			break;
 		}
 	}

 	LL ans = 0;
 	for (int i = 1; i <= n; i ++ )
 	{
 		ans += (b[i].first * b[i].second);
 	}
 	std::cout << ans << "\n";
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

