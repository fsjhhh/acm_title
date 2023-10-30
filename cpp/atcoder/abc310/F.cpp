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

const int N = 110, M = 1 << 11, mod = 998244353;
LL a[N], f[N][M];

LL k_s(LL a, LL b, LL mod)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    LL n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        std::cin >> a[i];
    }

    f[0][1] = 1;
    for (int i = 1; i <= n; i ++ ) {
        LL inv = k_s(a[i], mod - 2, mod);
        for (int j = 0; j < M; j ++ ) {
            for (int k = 1; k <= std::min(a[i], 10LL); k ++ ) {
                f[i][j | ((j << k) & (M - 1))] += (f[i - 1][j] * inv % mod);
                if (f[i][j | ((j << k) & (M - 1))] >= mod)
                    f[i][j | ((j << k) & (M - 1))] -= mod;
            }
        }
        if (a[i] > 10) {
            for (int j = 0; j < M; j ++ ) {
                f[i][j] += f[i - 1][j] * (a[i] - 10) % mod * inv % mod;
                if (f[i][j] >= mod)
                    f[i][j] -= mod;
            }
        }
    }
    LL ans = 0;
    for (int i = 0; i < M; i ++ ) {
        if ((i >> 10) & 1) {
            ans += f[n][i];
            if (ans >= mod)
                ans -= mod;
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


