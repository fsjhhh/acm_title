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
int a[N];
bool st[N];

int n, ans;
std::map<int, int> s;

void dfs(int u, int step) {
	if (!st[u]) {
		st[u] = true;
		s[u] = step;
		dfs(a[u], step + 1);
	}
	else {
		if (s.find(u) == s.end()) {
			return ;
		}
		else {
			ans += (step - s[u]);
		}
	}
}

void solve()
{
	std::cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		std::cin >> a[i];
	}

	for (int i = 1; i <= n; i ++ ) {
		if (!st[i]) {
			s.clear();
			dfs(i, 1);
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