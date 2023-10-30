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

const int N = 60;
std::vector<std::pair<int, std::vector<int>>> h;

bool cmp(std::pair<int, std::vector<int>> a, std::pair<int, std::vector<int>> b)
{
	return a.first < b.first;
}

void solve()
{
	int n, t;
	std::cin >> n >> t;
	for (int i = 1; i <= n; i ++ )
	{
		std::vector<int> v;
		int x, m;
		std::cin >> x >> m;
		for (int j = 1; j <= m; j ++ )
		{
			int y;
			std::cin >> y;
			v.push_back(y);
		}
		h.push_back({x, v});
	}
	std::sort(h.begin(), h.end(), cmp);
	int ans = 0;
	for (int i = 0; i < n; i ++ )
	{
		int a = h[i].first;
		if (a > t)
			break;
		std::vector<int> b;
		for (int j = 0; j <= i; j ++ )
			for (auto it : h[j].second)
				b.push_back(it);
		std::sort(b.begin(), b.end());
		int now = t - a;
		int res = 0;
		for (auto it : b)
		{
			if (now >= it)
			{
				res ++ ;
				now -= it;
			}
			else
				break;
		}
		ans = std::max(ans, res);
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

