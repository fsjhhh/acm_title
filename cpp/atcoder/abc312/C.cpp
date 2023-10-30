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
const LL e = 1e18;
LL a[N], b[N];
LL n, m;

bool check(LL x) {
	LL _1 = 0, _2 = 0;
	for (int i = 1; i <= n; i ++ ) {
		if (a[i] <= x) {
			_1 ++ ;
		}
	}

	for (int i = 1; i <= m; i ++ ) {
		if (b[i] >= x) {
			_2 ++ ;
		}
	}

	if (_1 >= _2) {
		return true;
	}
	else {
		return false;
	}

}

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
    }
    for (int i = 1; i <= m; i ++ ) {
    	std::cin >> b[i];
    }

    LL l = 1, r = e;
    while (l < r) {
    	LL mid = (l + r) >> 1;
    	if (check(mid)) {
    		r = mid;
    	}
    	else {
    		l = mid + 1;
    	}
    }

    std::cout << l << "\n";

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