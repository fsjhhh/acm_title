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
LL sum[N];

void solve()
{
    memset(sum, 0, sizeof sum);
    LL n, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> a[i];
    }
    std::sort(a, a + n);
    for (int i = 0; i < n; i ++ ) {
    	sum[i + 1] = sum[i] + a[i];
    }

    LL ans = INFL;
    for (int i = 0; i < n; i ++ ) {
        LL x = (k - sum[n - i] + sum[1]);
        LL y = i + 1;
        LL t = x / y;
        if (t * y > x)
            t -- ;
        // std::cout << t << "\n";
        ans = std::min(i + std::max(0LL, a[0] - t), ans);
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