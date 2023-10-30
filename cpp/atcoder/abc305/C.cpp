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
#include <iomanip> // std::fixed() std::setprecision(x) 保留x位小数
#include <array>
//#include <bits/stdc++.h>
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
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> mp(h);
    for (int i = 0; i < h; i ++ ) {
    	std::cin >> mp[i];
    }

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    auto check = [&](int x, int y) -> bool {
    	int num = 0;
    	for (int i = 0; i < 4; i ++ ) {
    		int tx = x + dx[i], ty = y + dy[i];
    		if (tx >= h || ty >= w || tx < 0 || ty < 0) {
    			continue;
    		}
    		if (mp[tx][ty] == '#') {
    			num ++ ;
    		}
    	}
    	if (num >= 2) {
    		return true;
    	}
    	else {
    		return false;
    	}
    };

    for (int i = 0; i < h; i ++ ) {
    	for (int j = 0; j < w; j ++ ) {
    		if (mp[i][j] == '.') {
    			if (check(i, j)) {
    				std::cout << i + 1 << " " << j + 1 << "\n";
    				return ;
    			}
    		}
    	}
    }

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