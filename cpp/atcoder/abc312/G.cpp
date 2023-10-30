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
LL si[N];
std::vector<int> edges[N];
int n;

LL dfs(int u, int fa) {
	si[u] = 1;
	for (auto v : edges[u]) {
		if (v == fa)
			continue;
		si[u] += dfs(v, u);
	}
	return si[u];
}

void solve()
{
	std::cin >> n;
	for (int i = 1; i < n; i ++ ) {
		int u, v;
		std::cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(1, -1);

	LL ans = 0;
	for (int u = 1; u <= n; u ++ ) {
		LL n_1 = 0, n_2 = 0, n_3 = 0;
		for (auto v : edges[u]) {
			LL num = si[v];
			if (si[v] > si[u]) {
				num = n - si[u];
			}
			n_3 += n_2 * num;
			n_2 += n_1 * num;
			n_1 += num;
		}
		ans += n_3;
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