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
std::vector<int> edges[N];
LL w[N], siz[N], st[N];

void bfs() {
	std::queue<int> q;
	q.push(1);
	siz[1] = 1;
	st[1] = 1;
	while (q.size()) {
		auto t = q.front();
		q.pop();
		for (auto v : edges[t]) {
			if (!st[v]) {
				st[v] = true;
				siz[v] = siz[t] + 1;
				q.push(v);
			}
		}
	}
}

void solve()
{
 	int n;
 	std::cin >> n;
 	for (int i = 1; i < n; i ++ ) {
 		int u, v;
 		std::cin >> u >> v;
 		edges[u].push_back(v);
 		edges[v].push_back(u);
 	}
 	for (int i = 1; i <= n; i ++ ) {
 		std::cin >> w[i];
 	}
 	bfs();
 	std::sort(w + 1, w + n + 1);
 	std::sort(siz + 1, siz + n + 1);
 	LL ans = 0;
 	for (int i = 1; i <= n; i ++ ) {
 		ans += w[i] * siz[i];
 	}
 	std::cout << ans << '\n';
 	for (int i = 1; i <= n; i ++ ) {
 		edges[i].clear();
 	}
 	memset(st, 0, sizeof st);
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