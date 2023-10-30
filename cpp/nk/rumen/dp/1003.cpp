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

LL dfs(LL n)
{
	if (n == 0 || n == 1 || n == 2)
		return 0;
	if (n == 3)
		return 1;
	if (n % 2)
		return dfs(n / 2) + dfs(n / 2 + 1) + 1;
	else
		return dfs(n / 2) * 2;
}

void solve()
{
	LL n;
	std::cin >> n;
	std::cout << dfs(n) << "\n";
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
