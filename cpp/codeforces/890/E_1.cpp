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
#include <bitset>
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

#define int long long

const int N = 5010;
std::vector<int> edges[N];
int sz[N], err[N][N];
std::bitset<N> q;

void dfs(int u) {
	sz[u] = 1;
	for (auto it : edges[u]) {
		dfs(it);
		sz[u] += sz[it];
		err[u][it] = sz[it];
	}
}

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i < n; i ++ ) {
		int x;
		std::cin >> x;
		edges[x].push_back(i + 1);
	}
	dfs(1);
	int ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		int num = edges[i].size();
		if (num == 0) {
			continue;
		}
		std::vector<int> arr;
		std::vector<int> f(n + 5);
		for (auto it : edges[i]) {
			arr.push_back(err[i][it]);
		}
		for (int j = 0; j <= sz[i]; j ++ ) {
			q[j] = 0;
		}
		q[0] = 1;
		for (auto it : arr) {
			q |= (q << it);
		}
		LL maxx = 0;
		for (int j = 1; j < sz[i]; j ++ ) {
			if (q[j]) {
				maxx = std::max(maxx, j * (sz[i] - j - 1));
			}
		}
		f[0] = 1;
		// for (auto it : arr) {
		// 	for (int j = n; j >= 0; j -- ) {
		// 		if (f[j]) {
		// 			f[j + it] = 1;
		// 		}
		// 	}
		// }
		// LL maxx = 0;
		// for (int j = 1; j <= n; j ++ ) {
		// 	if (f[j]) {
		// 		maxx = std::max(maxx, j * (sz[i] - 1 - j));
		// 	}
		// }
		ans += maxx;
	}	
	std::cout << ans << "\n";
}

signed main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

