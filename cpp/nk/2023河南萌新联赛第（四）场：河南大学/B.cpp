// Problem: 序列的与和
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/62880/B
// Memory Limit: 524288 MB
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

const int N = 25;
LL a[N], n, m;
LL ans = 0;
bool pd = false;

bool check(LL x) {
	LL k = 0;
	for (int i = 0; i <= 63; i ++ ) {
		if (x >> i & 1) {
			k ++ ;
		}
	}
	if (k >= m) {
		if (k == m) {
			ans ++ ;
		}
		return true;
	}
	else {
		return false;
	}
}

void dfs(LL u, LL pos) {
	if (u > n) {
		return ;
	}
	else {
		for (int i = u + 1; i <= n; i ++ ) {
			check(pos & a[i]);
			dfs(i, pos & a[i]);
		}
	}
}

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
    }
    
    for (int i = 1; i <= n; i ++ ) {
    	check(a[i]);
    }
    
    for (int i = 1; i <= n; i ++ ) {
    	pd = false;
    	dfs(i, a[i]);
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