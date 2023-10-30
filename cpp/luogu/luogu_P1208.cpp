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
#define IOS std::ios::sync_with_stdio(false); \
            std::cin.tie(0);              \
            std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 5010;
std::vector<PII> v;

void solve()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= m; i ++ )
	{
		int x, y;
		std::cin >> x >> y;
		v.push_back({x, y});
	}

	std::sort(v.begin(), v.end());

	int ans = 0;
	for (auto a : v)
	{
		int x = a.first, y = a.second;
		y = std::min(n, y);
		ans += x * y;
		n -= y;
	}

	std::cout << ans << std::endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
