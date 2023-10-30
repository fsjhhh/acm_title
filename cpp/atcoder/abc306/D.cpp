// Problem: D - Poisonous Full-Course
// Contest: AtCoder - Toyota Programming Contest 2023#3（AtCoder Beginner Contest 306）丰田编程大赛2023#3（AtCoder初学者大赛306）
// URL: https://atcoder.jp/contests/abc306/tasks/abc306_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
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

const int N = 3e5 + 10;
PII a[N];
LL f[N][2];

void solve()
{
 	int n;
 	std::cin >> n;
 	for (int i = 1; i <= n; i ++ ) {
 		std::cin >> a[i].first >> a[i].second;
 	}
 	
 	for (int i = 1; i <= n; i ++ ) {
 		if (a[i].first == 0) {
 			f[i][0] = std::max(f[i - 1][0] + a[i].second, std::max(f[i - 1][1] + a[i].second, f[i - 1][0]));
 			f[i][1] = f[i - 1][1];
 		}
 		else {
 			f[i][0] = f[i - 1][0];
 			f[i][1] = std::max(f[i - 1][0] + a[i].second, f[i - 1][1]);
 		}
 	}
 	
 	std::cout << std::max(f[n][0], f[n][1]) << "\n";
 	
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