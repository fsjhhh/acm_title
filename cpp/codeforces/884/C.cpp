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
LL a[N], cnt, f[N];

void solve()
{
    cnt = 0;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        std::cin >> a[i];
    }

    f[1] = a[1];
    f[2] = a[2];
    for (int i = 3; i <= n; i ++ )
    {
        f[i] = std::max(a[i], std::max(f[i - 2], f[i - 2] + a[i]));
    }
    LL ans = -INFL;
    for (int i = 1; i <= n; i ++ )
        ans = std::max(ans, f[i]);
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

