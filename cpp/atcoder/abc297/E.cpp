// Problem: E - Kth Takoyaki Set
// Contest: AtCoder - AtCoder Beginner Contest 297AtCoder 初学者竞赛 297
// URL: https://atcoder.jp/contests/abc297/tasks/abc297_e
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
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

const int N = 15;
LL a[N];
std::set<LL> s;

void solve()
{
 	int n, k;
 	std::cin >> n >> k;
 	for (int i = 1; i <= n; i ++ ) {
 		std::cin >> a[i];
 		s.insert(a[i]);
 	}
 	
 	k -- ;
 	while (k -- ) {
 		LL t = *s.begin();
 		s.erase(s.begin());
 		for (int i = 1; i <= n; i ++ ) {
 			s.insert(t + a[i]);
 		}
 	}
 	
 	std::cout << *s.begin() << "\n";
 	
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