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

struct Node {
	int x, y, dc;
};

void solve()
{
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> mp(h);
    for (int i = 0; i < h; i ++ ) {
    	std::cin >> mp[i];
    }
    std::queue<Node> q;
    Node start, end;
    int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
    for (int i = 0; i < h; i ++ ) {
    	for (int j = 0; j < w; j ++ ) {
    		if (mp[i][j] == 'S') {
    			start.x = i, start.y = j;
    		}
    		if (mp[i][j] == 'G') {
    			end.x = i, end.y = j;
    		}
    		if (mp[i][j] == '<') {
    			q.push({i, j, 0});
    			mp[i][j] = '#';
    		}
    		if (mp[i][j] == '>') {
    			q.push({i, j, 2});
    			mp[i][j] = '#';
    		}
    		if (mp[i][j] == 'v') {
    			q.push({i, j, 3});
    			mp[i][j] = '#';
    		}
    		if (mp[i][j] == '^') {
    			q.push({i, j, 1});
    			mp[i][j] = '#';
    		}
    	}
    }
    auto bfs = [&]() -> void {
    	while (q.size()) {
    		auto t = q.front();
    		q.pop();
    		int tx = t.x + dx[t.dc], ty = t.y + dy[t.dc];
    		if (tx >= 0 && tx < h && ty >= 0 && ty < w && mp[tx][ty] != '#') {
    			mp[tx][ty] = '!';
    			q.push({tx, ty, t.dc});
    		}
    	}
    };
    bfs();
    std::queue<PII> qq;
    qq.push({start.x, start.y});
    std::vector d(h, std::vector<int>(w, -1));
    d[start.x][start.y] = 0;
    while (qq.size()) {
    	auto t = qq.front();
    	qq.pop();
    	for (int i = 0; i < 4; i ++ ) {
    		int tx = t.first + dx[i], ty = t.second + dy[i];
    		if (tx >= 0 && tx < h && ty >= 0 && ty < w && mp[tx][ty] != '#' && mp[tx][ty] != '!' && d[tx][ty] == -1) {
    			d[tx][ty] = d[t.first][t.second] + 1;
    			qq.push({tx,ty});
    		}
    	}
    }
    std::cout << d[end.x][end.y] << "\n";
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