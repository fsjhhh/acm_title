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
std::vector<int> v[N];

bool cmp(int a, int b)
{
	return a > b;
}

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ )
		v[i].clear();

	for (int i = 1; i <= n; i ++ )
	{
		int x, y;
		std::cin >> x >> y;
		v[x].push_back(y);
	}

	LL ans = 0;
	for (int i = 1; i <= n; i ++ )
	{
		std::sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < std::min((int)v[i].size(), i); j ++ )
			ans += v[i][j];
	}
	std::cout << ans << "\n";
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
