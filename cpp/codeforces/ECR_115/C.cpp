// Problem: C. Delete Two Elements C. 删除两个元素
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)Educational Codeforces 第 115 轮（评级为 Div. 2）
// URL: https://codeforces.com/contest/1598/problem/C
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
LL a[N];

std::map<LL, LL> m;

void solve()
{
    int n;
    std::cin >> n;
    LL sum = 0;
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
    	sum += a[i];
    }
    LL t = sum * 2 / n;
    if (t * n != sum * 2) {
    	std::cout << 0 << "\n";
    	return ;
    }
    
    LL ans = 0;
    for (int i = 1; i <= n; i ++ ) {
    	if (m.find(t - a[i]) != m.end()) {
    		ans += m[t - a[i]];
    	}
    	m[a[i]] ++ ;
    }
    
    std::cout << ans << "\n";
    
    m.clear();
    
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