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

void solve()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> b(n + 1);
    std::vector<bool> st(n + 1, 0);
    for (int i = 1; i <= n; i ++ ) {
    	int c;
    	std::cin >> c;
    	for (int j = 1; j <= c; j ++ ) {
    		int p;
    		std::cin >> p;
    		b[i].push_back(p);
    	}
    }
    auto dfs = [&](auto self, int u) -> void {
    	if (st[u]) {
    		return ;
    	}
    	for (auto it : b[u]) {
    		self(self, it);
    	}
    	st[u] = true;
    	if (u != 1) {
    		std::cout << u << " ";
    	}
    };
    dfs(dfs, 1);
    std::cout << "\n";
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