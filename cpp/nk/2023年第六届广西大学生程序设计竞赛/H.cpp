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
 	LL m, a, l = 0, res = 1;
 	std::cin >> m >> a;
 	for (int i = 1; i <= m; i ++ ) {
 		LL x, y;
 		std::cin >> x >> y;
 		l = std::max(l, y);
 		if (i == 1)
 			res = x - y;
 		else
 			res = std::__gcd(x - y, res);
 	}

 	if (res == 0) {
 		std::cout << a - l << "\n";
 		return ;
 	}

 	LL ans = 0;
 	for (int i = 1; i <= res / i; i ++ ) {
 		if (res % i == 0) {
 			if (i * i != res) {
 				if (i > l && i <= a)
 					ans ++ ;
 				if (res / i > l && res / i <= a)
 					ans ++ ;
 			}
 			else {
 				if (i > l && i <= a)
 					ans ++ ;
 			}
 		}
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