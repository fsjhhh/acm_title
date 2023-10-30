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

#define int long long

const int N = 1e6 + 10;
LL a[N];

void solve()
{
 	int k;
 	std::cin >> k;
 	LL sum = 0;
 	for (int i = 0; i < k; i ++ ) {
 		std::cin >> a[i];
 	}
 	int n, m, x, cnt = 0;
 	std::cin >> n >> m >> x;
    x %= m;
 	for (int i = 0; i < k; i ++ ) {
        a[i] %= m;
        if (a[i] == 0) {
            cnt ++ ;
        }
 		sum += a[i];
 	}
 	LL t_1 = n / k;
 	LL t_2 = n % k;
 	LL ans = t_1 * sum;
 	for (int i = 0; i < t_2; i ++ ) {
 		ans += a[i];
 	}
 	ans += x;
 	LL ca = ans / m;
 	std::cout << n - ca << "\n";
}

signed main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}