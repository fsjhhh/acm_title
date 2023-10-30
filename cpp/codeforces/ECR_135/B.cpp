// Problem: B. Best Permutation B. 最佳排列
// Contest: Codeforces - Educational Codeforces Round 135 (Rated for Div. 2)Educational Codeforces 第 135 轮（评级为 Div. 2）
// URL: https://codeforces.com/contest/1728/problem/B
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

void solve()
{
 	int n;
 	std::cin >> n;
 	if ((n - 3) % 2) {
 		for (int i = (n - 2); i >= 1; i -- ) {
 			std::cout << i << " ";
 		}
 		std::cout << n - 1 << " " << n << "\n";
 	}
 	else {
 		if ((n - 2) % 3 == 0 || (n - 2) % 3 == 2) {
 			for (int i = 2; i <= (n - 2); i ++ ) {
 				std::cout << i << " ";
 			}
 			std::cout << 1 << " " << n - 1 << " " << n << "\n";
 		}
 		else {
 			for (int i = (n - 2); i >= 4; i -- ) {
 				std::cout << i << " ";
 			}
 			std::cout << 2 << " " << 3 << " " << 1 << " " << n - 1 << " " << n << "\n";
 		}
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