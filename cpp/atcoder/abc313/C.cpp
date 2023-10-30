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
LL a[N], b[N];

void solve()
{
	int n;
	std::cin >> n;
	LL sum = 0;
	for (int i = 1; i <= n; i ++ ) {
		std::cin >> a[i];
		sum += a[i];
	} 
	LL ans = sum / n;
	LL t = sum - ans * n;
	for (int i = 1; i <= n - t; i ++ ) {
		b[i] = ans;
	}
	for (int i = n - t + 1; i <= n; i ++ ) {
		b[i] = ans + 1;
	}
	std::sort(a + 1, a + n + 1);
	LL res = 0;
	for (int i = 1; i <= n; i ++ ) {
		if (a[i] < b[i]) {
			res += (b[i] - a[i]);
		}
	}
	std::cout << res << "\n";
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