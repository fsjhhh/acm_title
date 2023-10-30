// Problem: E - Pac-Takahashi
// Contest: AtCoder - Panasonic Programming Contest 2023（AtCoder Beginner Contest 301）
// URL: https://atcoder.jp/contests/abc301/tasks/abc301_e
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

const int N = 310;
char mp[N][N];
int h, w, t;

std::map<PII, int> ca;
std::map<int, PII> invca;
int idx, start_x, start_y, end_x, end_y;
int dis[20][20], dist[N][N];

int f[1 << 19][20];

int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

void bfs(int x, int y) {
	memset(dist, 0x3f, sizeof dist);
	std::queue<PII> q; 
	dist[x][y] = 0;
	q.push({x, y});
	while (q.size()) {
		auto [_x, _y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i ++ ) {
			int t_x = _x + dx[i], t_y = _y + dy[i];
			if (t_x >= 1 && t_x <= h && t_y >= 1 && t_y <= w && mp[t_x][t_y] != '#' && dist[t_x][t_y] > dist[_x][_y] + 1) {
				dist[t_x][t_y] = dist[_x][_y] + 1;
				q.push({t_x, t_y});
			}
		}
	}
}

int calc(int x) {
	int res = 0;
	for (int i = 0; i < 19; i ++ ) {
		if (x >> i & 1)
			res ++ ;
	}
	return res;
}

void solve()
{
	memset(f, 0x3f, sizeof f);
    std::cin >> h >> w >> t;
    for (int i = 1; i <= h; i ++ ) {
    	for (int j = 1; j <= w; j ++ ) { 
    		std::cin >> mp[i][j];
    		if (mp[i][j] == 'o') {
    			ca[{i, j}] = idx;
    			invca[idx] = {i, j};
    			idx ++ ;
    		}
    		if (mp[i][j] == 'S') {
    			start_x = i;
    			start_y = j;
    		}
    		if (mp[i][j] == 'G') {
    			end_x = i;
    			end_y = j;
    		}
    	}
    }
    
    for (auto [key, value] : ca) {
    	bfs(key.first, key.second);
    	for (auto [pos, id] : ca) {
    		dis[value][id] = dist[pos.first][pos.second];
    	}
    }
    
    bfs(start_x, start_y);
    if (dist[end_x][end_y] > t) {
    	std::cout << -1 << "\n";
    	return ;
    }
    
    for (auto [pos, id] : ca) {
    	f[(1 << id)][id] = dist[pos.first][pos.second];
    }
    bfs(end_x, end_y);
    int ans = 0, status = (1 << idx);
    for (int i = 0; i < status; i ++ ) {
    	for (int j = 0; j < idx; j ++ ) {
    		if ((i >> j) & 1) {
    			for (int k = 0; k < idx; k ++ ) {
    				if (((~i >> k) & 1) && (f[i][j] + dis[j][k] <= t)) {
    					f[i | (1 << k)][k] = std::min(f[i | (1 << k)][k], f[i][j] + dis[j][k]);
    				}
    			}
    			if (f[i][j] + dist[invca[j].first][invca[j].second] <= t) {
    				int num = calc(i);
    				ans = std::max(ans, num);
    			}
    		}
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