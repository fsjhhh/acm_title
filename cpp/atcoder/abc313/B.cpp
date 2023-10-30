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

const int N = 55, M = 3010;
int d[N];

void solve()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= m; i ++ ) {
		int a, b;
		std::cin >> a >> b;
		d[b] ++ ;
	}
	int pd = 0, ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		if (d[i] == 0) {
			ans = i;
			pd ++ ;
		}
	}
	if (pd >= 2) {
		std::cout << -1 << "\n";
	}
	else {
		std::cout << ans << "\n";
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