// Problem: D. Training Session D. 培训课程
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)Educational Codeforces 第 115 轮（评级为 Div. 2）
// URL: https://codeforces.com/contest/1598/problem/D
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

const int N = 2e5 + 10;
PLL a[N];

LL x_3[N];

void init() {
	LL z = 6;
	x_3[3] = 1;
	for (LL i = 4; i < N; i ++ ) {
		LL zn = i * (i - 1) * (i - 2);
		x_3[i] = zn / z;
	}
}

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i].first >> a[i].second;
    }
    
    LL ans = x_3[n];
    
    std::map<LL, LL> s, t;
    for (int i = 1; i <= n; i ++ ) {
    	s[a[i].first] ++ ;
    	t[a[i].second] ++ ;
    }
    
    for (int i = 1; i <= n; i ++ ) {
    	LL t1 = s[a[i].first];
    	LL t2 = t[a[i].second];
    	ans = (ans - (t2 - 1) * (t1 - 1));
    }
    
    std::cout << ans << "\n";
    
    
}

int main()
{
    IOS;
    init();
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}