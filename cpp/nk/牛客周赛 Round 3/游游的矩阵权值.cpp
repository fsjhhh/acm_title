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
const int mod = 1e9 + 7;

void solve()
{
    LL n;
    std::cin >> n;
    LL a = 4, b = 4 * (n - 2) + 4;
    LL ans = (1 + 4) * 4 / 2 * 2;
    ans = (ans + ((4 * (n - 2) % mod + 9) % mod * (2 * (n - 2) % mod)) * 3) % mod;
    ans = (ans + (((b + 1) % mod + n * n % mod) % mod * ((n - 2) * (n - 2) % mod) * 2)) % mod;
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