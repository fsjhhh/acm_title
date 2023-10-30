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
#include <iomanip> // std::fixed std::setprecision(x) 保留x位小数
#include <array>
#include <bitset>
#include <functional>
#include <ranges>
//#include <bits/stdc++.h>
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    std::cin >> n;
    std::vector mp(n, std::vector<LL>(n));
    for (int i = 0; i < n - 1; i ++ ) {
    	for (int j = i + 1; j < n; j ++ ) {
    		std::cin >> mp[i][j];
    	}
    }

    LL ans = 0, cnt = 0;
    std::vector<bool> st(n);
    auto dfs = [&](auto self, LL u, LL sum) -> void {
        if (st[u + 1]) {
    		self(self, u + 1, sum);
    		return ;
    	}
    	if (cnt == n || cnt == n - 1) {
    		ans = std::max(sum, ans);
    		return ;
    	}

    	for (int i = u + 2; i < n; i ++ ) {
    		if (!st[i]) {
    			st[u + 1] = true;
    			st[i] = true;
    			cnt += 2;
    			self(self, u + 1, sum + mp[u + 1][i]);
    			cnt -= 2;
    			st[u + 1] = st[i] = false;
    		}
    	}
    };
    if (n % 2 == 0) {
    	dfs(dfs, -1, 0);
    	std::cout << ans << "\n";
    	return ;
    }
    dfs(dfs, -1, 0);
    for (int i = 0; i < n; i ++ ) {
    	st.clear();
    	st.resize(n, 0);
    	st[i] = 1;
    	dfs(dfs, - 1, 0);
    }
    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}