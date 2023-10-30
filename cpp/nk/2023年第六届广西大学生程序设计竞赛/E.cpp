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
LL a[N];

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		std::cin >> a[i];
	}

	a[n + 1] = INFL;
	std::sort(a + 1, a + n + 1);
	LL ans = 0;
	int j = 1;
	LL mx = 0;
	for (int i = 1; i <= n; i ++ ) {
		int cnt = 0;
		// std::cout << i << "\n";
		j = i;
		while (j <= n && a[j] == a[i]) {
			j ++ ;
			cnt ++ ;
		}
		if (cnt % 2) {
			ans += (a[j] - a[i]);
			mx = std::max(mx, a[j] - a[i]);
			// std::cout << ans << "\n";
		}
		i = j - 1;
	}
	std::cout << ans - mx << "\n";

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