// Problem: A. Computer Game A、电脑游戏
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)Educational Codeforces 第 115 轮（评级为 Div. 2）
// URL: https://codeforces.com/contest/1598/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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

const int N = 110;
char mp[2][N];
bool st[2][N];
int dx[] = {1, 0, 1, -1, -1}, dy[] = {0, 1, 1, 0, 1};
int n;

void bfs() {
	std::queue<PII> q;
	st[0][0] = true;
	q.push({0, 0});
	while (q.size()) {
		auto [x, y] = q.front();A
		q.pop();
		for (int i = 0; i < 5; i ++ ) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx >= 0 && tx < 2 && ty >= 0 && ty < n && mp[tx][ty] == '0' && !st[tx][ty]) {
				st[tx][ty] = true;
				if (tx == 1 && ty == n - 1)
					return ;
				q.push({tx, ty});
			}
		}
	}
}

void solve()
{
	memset(st, 0, sizeof st);
 	std::cin >> n;
 	for (int i = 0; i < 2; i ++ ) {
 		for (int j = 0; j < n; j ++ ) {
 			std::cin >> mp[i][j];
 		}
 	}
 	
 	bfs();
 	
 	if (st[1][n - 1]) {
 		std::cout << "YES" << "\n";
 	}
 	else {
 		std::cout << "NO" << "\n";
 	}
 	
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