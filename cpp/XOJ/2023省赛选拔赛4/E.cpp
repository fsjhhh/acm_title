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
const LL INFL = 1e18;

void solve()
{
 	LL n, k, m, a, b;
 	std::cin >> n >> k >> m >> a >> b;
 	LL ans = INFL;
 	if (n % m == 0) {
 		std::cout << 0 << "\n";
 		return ;
 	}
 	if (k == 1) {
 		std::cout << -1 << "\n";
 		return ;
 	}
    LL c = 0;
 	while (1) {
        //  log k n * log k p
        //  k ^ p * n -> k ^ p * (n + 1) - 1 有没有 m 的倍数
        //  k ^ p * n + k ^ p - 1
        //  (m - (k ^ p * n) % m) % m <= k ^ p - 1
 		LL d = n % m, p = 1;
        for (int i = 0; ; i ++ ) {
            LL t = (m - d) % m; 
            if (t < p) {
                LL sum = c * b + i * a;
                ans = std::min(ans, sum);
                break;
            }
            p *= k;
            d = (d * k) % m;
        }
        if (n == 0) {
            break;
        }
        c ++ ;
        n /= k;
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
