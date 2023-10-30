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

const int N = 1e4 + 10, M = 110;
LL a[N][M];
LL tr[N * M];

std::vector<LL> v;

LL lowbit(LL x) {
	return x & -x;
}

void update(LL k, LL x) {
	for (int i = k; i <= v.size(); i += lowbit(i)) {
		tr[i] += x;
	}
}

LL find(LL x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

LL getsum(LL k) {
	LL res = 0;
	for (int i = k; i > 0; i -= lowbit(i)) {
		res += tr[i];
	}
	return res;
}

void solve()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= m; j ++ ) {
			std::cin >> a[i][j];
			v.push_back(a[i][j]);
		}
	}

	std::sort(v.begin(), v.end());
	// v.erase(std::unique(v.begin(), v.end()), v.end());
	// for (int i = 0; i < v.size(); i ++ ) {
	// 	std::cout << v[i] << " \n"[i == v.size() - 1];
	// }
	LL ans = 0;
	for (int i = n; i >= 1; i -- ) {
		for (int j = 1; j <= m; j ++ ) {
			ans += j * (n - i) + getsum(find(a[i][j]) - 1);
		}
		for (int j = 1; j <= m; j ++ ) {
			update(find(a[i][j]), 1);
		}
	}
	std::cout << ans << "\n";
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