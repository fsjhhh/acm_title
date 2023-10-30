// Problem: B - The Middle Day
// Contest: AtCoder - KEYENCE Programming Contest 2023 Summer（AtCoder Beginner Contest 315）
// URL: https://atcoder.jp/contests/abc315/tasks/abc315_b
// Memory Limit: 1024 MB
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
 	int m;
 	std::cin >> m;
 	std::vector<int> v(m + 1), sum(m + 1);
 	for (int i = 1; i <= m; i ++ ) {
 		std::cin >> v[i];
 		sum[i] = sum[i - 1] + v[i];
 	}   
 	int d = (sum[m] + 1) / 2;
 	int a, b;
 	for (int i = m; i >= 0; i -- ) {
 		if (sum[i] < d) {
 			a = i + 1;
 			b = d - sum[i];
 			break;
 		}
 	}
 	std::cout << a << " " << b << "\n";
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