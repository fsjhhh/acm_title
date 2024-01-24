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
// #include <bits/stdc++.h>
// priority_queue 优先队列
// std::cout.flush(); 交互题
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
    int n, m, p, k;
    std::cin >> n >> m >> p >> k;
    std::vector<std::string> mp(n);
    PII st, ed;
    for (int i = 0; i < n; i++) {
    	std::cin >> mp[i];
    	for (int j = 0; j < m; j++) {
    		if (mp[i][j] == 's') {
    			st = {i, j};
    		} else if (mp[i][j] == 'e') {
    			ed = {i, j};
    		}
    	}
    }

    struct node {
    	int x, y, ti, ya;
    };
    std::vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
    std::queue<node> q;
    q.push({st.first, st.second, p, k});
    std::vector pd(n, std::vector(m, std::vector(p + 1, std::vector<bool>(k + 1))));
    pd[st.first][st.second][p][k] = true;
    while (q.size()) {
    	auto [X, Y, P, K] = q.front();
    	q.pop();
    	for (int i = 0; i < 4; i++) {
    		int tx = X + dx[i], ty = Y + dy[i];
    		if (tx < 0 || ty < 0 || tx >= n || ty >= m || mp[tx][ty] == 'w') {
    			continue;
    		}
    		if (mp[tx][ty] == 'r') {
    			int tp = P - 1, tk = K;
    			if (tp >= 0) {
    				if (pd[tx][ty][tp][tk]) {
    					continue;
    				}
    				q.push({tx, ty, tp, tk});
    				pd[tx][ty][tp][tk] = true;
    			}
    		} else if (mp[tx][ty] == 'd') {
    			int tp = P - 1, tk = K - 1;
    			if (tp >= 0 && tk >= 0) {
    				if (pd[tx][ty][tp][tk]) {
	    				continue;
	    			}
    				q.push({tx, ty, tp, tk});
    				pd[tx][ty][tp][tk] = true;
    			}
    		} else {
    			int tp = P - 1;
    			if (tp >= 0) {
    				std::cout << "YES\n";
    				return ;
    			}
    		}
    	}

    }
    std::cout << "NO\n";
    
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}