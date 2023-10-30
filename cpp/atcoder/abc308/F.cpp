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
LL p[N], d[N], l[N];
bool st[N];
PLL q[N];

bool cmp(PLL a, PLL b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

void solve()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		std::cin >> p[i];

	for (int i = 1; i <= m; i ++ )
		std::cin >> l[i];
    
	for (int i = 1; i <= m; i ++ )
		std::cin >> d[i];

	for (int i = 1; i <= m; i ++ )
		q[i] = {l[i], d[i]};
	std::sort(q + 1, q + m + 1, cmp);
	std::sort(p + 1, p + n + 1);
	std::priority_queue<LL> Q;
	LL ans = 0;
	for (int i = 1, j = 1; i <= n; i ++ )
	{
		while (j <= m && q[j].first <= p[i])
		{
			Q.push(q[j].second);
			j ++ ;
		}
		if (Q.size())
		{
			ans -= Q.top();
			Q.pop();
		}
		ans += p[i];
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