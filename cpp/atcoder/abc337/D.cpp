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
    int h, w, k;
    std::cin >> h >> w >> k;
    std::vector<std::string> mp(h);
    for (int i = 0; i < h; i++) {
    	std::cin >> mp[i];
    }

    std::vector col(h, std::vector<bool>(w)), row(h, std::vector<bool>(w));

    std::vector<int> dx = {1, 0}, dy = {0, 1};
    int ans = INF;
    auto check = [&](int x, int y, int d) -> void {
    	std::queue<PII> q;
    	int z = 0;
    	while (x < h && y < w && mp[x][y] != 'x') {
    		if (d == 0) {
    			col[x][y] = true;
    		} else {
    			row[x][y] = true;
    		}
    		if (mp[x][y] == '.') {
    			z ++ ;
    		}
    		if (q.size() >= k) {
    			auto [a, b] = q.front();
    			q.pop();
    			if (mp[a][b] == '.') {
    				z -- ;
    			}
    		}
    		q.push({x, y});
	   		x += dx[d], y += dy[d];
	   		if (q.size() == k) {
	   			ans = std::min(ans, z);
	   		}
    	}
    };

    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		if (mp[i][j] == 'x') {
    			continue;
    		}
    		if (!col[i][j]) {
    			check(i, j, 0);
    		}
    		if (!row[i][j]) {
    			check(i, j, 1);
    		}
       	}
    }

    std::cout << (ans == INF ? -1 : ans) << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}