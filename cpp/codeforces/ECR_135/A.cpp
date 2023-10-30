// Problem: A. Colored Balls: RevisitedA. 彩球：重温
// Contest: Codeforces - Educational Codeforces Round 135 (Rated for Div. 2)Educational Codeforces 第 135 轮（评级为 Div. 2）
// URL: https://codeforces.com/contest/1728/problem/A
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

const int N = 210;
int a[N];

void solve()
{
 	int n;
 	std::cin >> n;
 	int ans = 0, res = 0;
 	for (int i = 1; i <= n; i ++ ) {
 		std::cin >> a[i];
 		if (res <= a[i]) {
 			res = a[i];
 			ans = i;
 		}
 	}
 	
 	std::cout << ans << "\n";
 	
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