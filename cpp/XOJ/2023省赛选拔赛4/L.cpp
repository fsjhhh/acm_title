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

const int N = 1e5 + 10;
PLL a[N], b[N];
int n;

bool cmp1(PLL x, PLL y) {
	return (x.first + x.second) > (y.first + y.second);
}

bool cmp2(PLL x, PLL y) {
	return (x.second > y.second);
}

bool check(LL x) {
	std::vector<LL> h, w;
	for (int i = 1; i <= n; i ++ ) {
		if (a[i].first >= x) {
			h.push_back(a[i].first + a[i].second - x);
		}
	}
	for (int i = 1; i <= n; i ++ ) {
		if (b[i].first < x) {
			w.push_back(b[i].second);
		}
	}
	if (h.size() < w.size()) {
		return false;
	}
	for (int i = 0; i < w.size(); i ++ ) {
		if (w[i] > h[i]) {
			return false;
		}
	}
	return true;
}

void solve()
{

	std::cin >> n;
	LL l = INFL, r = 0;;
	for (int i = 1; i <= n; i ++ ) {
		LL v, w;
		std::cin >> v >> w;
		a[i] = {v, w};
		b[i] = {v, w};
		l = std::min(l, (LL)v);
		r = std::max(r, (LL)v);
	}
	std::sort(a + 1, a + n + 1, cmp1);
	std::sort(b + 1, b + n + 1, cmp2);
	while (l < r) {
		LL mid = (l + r + 1) >> 1;
		if (check(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	std::cout << l << "\n";

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