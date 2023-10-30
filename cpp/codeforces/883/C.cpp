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
std::pair<LL, std::pair<LL, LL>> a[N];
LL b[N], idx;

bool cmp(std::pair<LL, std::pair<LL, LL>> x, std::pair<LL, std::pair<LL, LL>> y)
{
	if (x.second.first == y.second.first && x.second.second == y.second.second)
		return x.first < y.first;
	if (x.second.first == y.second.first)
		return x.second.second < y.second.second;
	return x.second.first > y.second.first;
}

void solve()
{
	LL n, m, h, idx = 0;
	std::cin >> n >> m >> h;
	for (LL i = 1; i <= n; i ++ )
	{
		for (LL j = 1; j <= m; j ++ )
			std::cin >> b[j];
		std::sort(b + 1, b + m + 1);
		LL ans = 0, res = 0, ans_1 = 0;
		while (ans + b[res + 1] <= h && res + 1 <= m)
		{
			ans += b[res + 1];
			ans_1 += ans;
			res ++ ;
		}
		a[i] = {i, {res, ans_1}};
	}
	std::sort(a + 1, a + n + 1, cmp);
	for (LL i = 1; i <= n; i ++ )
	{
		if (a[i].first == 1)
		{
			std::cout << i << "\n";
			return ;
		}
	}
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}