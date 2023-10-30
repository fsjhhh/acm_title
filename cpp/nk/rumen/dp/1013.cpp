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
int a[N];
LL s[N];

bool cmp(int x, int y)
{
	return x > y;
}

void solve()
{
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; i ++ )
	{
		std::cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	LL maxx = -INFL, ans = -INFL;
	for (int i = k; i <= n - k; i ++ )
	{
		maxx = std::max(maxx, s[i] - s[i - k]);
		ans = std::max(ans, maxx + s[i + k] - s[i]);
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
