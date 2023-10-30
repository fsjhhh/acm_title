// Problem: B. Groups B. 团体
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)Educational Codeforces 第 115 轮（评级为 Div. 2）
// URL: https://codeforces.com/contest/1598/problem/B
// Memory Limit: 256 MB
// Time Limit: 4000 ms

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

const int N = 1e5 + 10;
int ti[N][6];

void solve()
{
 	int n;
 	std::cin >> n;
 	for (int i = 1; i <= n; i ++ ) {
 		for (int j = 1; j <= 5; j ++ ) {
 			std::cin >> ti[i][j];
 		}
 	}
 	
 	for (int i = 1; i <= 5; i ++ ) {
 		for (int j = i + 1; j <= 5; j ++ ) {
 			int _0 = 0, _1 = 0, _2 = 0;
 			for (int k = 1; k <= n; k ++ ) {
 				if (ti[k][i] != ti[k][j]) {
 					_0 += ti[k][i];
 					_1 += ti[k][j];
 				}
 				else {
 					if (ti[k][i] == 1) {
 						_2 ++ ;
 					}
 					else {
 						continue;
 					}
 				}
 			}
 			if (_2 == 0) {
 				if (_0 + _1 == n && _1 == n / 2) {
 					std::cout << "YES" << "\n";
 					return ;
 				}
 			}
 			else {
 				int t = n / 2;
 				if (_0 > t || _1 > t) {
 					continue;
 				}
 				if (_0 + _1 + _2 == n) {
 					std::cout << "YES" << "\n";
 					return ;
 				}
 			}
 		}
 	}
 	std::cout << "NO" << "\n";
 	
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