// Problem: 平均数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/62880/E
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

const int N = 1e6 + 10;
LL a[N];

void solve()
{
    LL n, m;
    std::cin >> n >> m;
    LL t = m / n;
    LL tt = m % n;
    for (int i = 1; i <= n; i ++ ) {
    	a[i] = t;
    }
    for (int i = 1; i <= tt; i ++ ) {
    	a[i] ++ ;
    }
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++ ) {
    	std::cout << a[i] << " ";
    }
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