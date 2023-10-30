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

const int N = 110;
const LL e = 1e18;
LL a[N];
LL n, h;

bool check(LL x) {
	LL ans = h;
	for (int i = 1; i < n; i ++ ) {
		if (a[i] + x - 1 >= a[i + 1]) {
			ans -= a[i + 1] - a[i];
		}
		else {
			ans -= x;
		}
		if (ans <= 0) {
			return true;
		}
	}
	ans -= x;
	if (ans > 0) {
		return false;
	}
	else {
		return true;
	}
}

void solve()
{
    std::cin >> n >> h;
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
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
    std::cout << r << "\n";

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