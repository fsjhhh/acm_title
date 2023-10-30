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

const int N = 1e5 + 10, mod = 1e9 + 7;;
LL a[N], p[N];
LL f[35][35][2][2];

void solve()
{
	int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
        std::cin >> a[i];
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= 31; j ++ )
            for (int k = 0; k <= 31; k ++ )
                f[j][k][a[i] >> j & 1][a[i] >> k & 1] ++ ;

    p[0] = 1;
    for (int i = 1; i <= 63; i ++ )
        p[i] = p[i - 1] * 2 % mod;

    LL res = 0;
    for (int i = 0; i <= 31; i ++ )
        for (int j = 0; j <= 31; j ++ )
            for (int x = 0; x < 2; x ++ )
                for (int y = 0; y < 2; y ++ )
                    res = (res + (f[i][j][x][y] * f[i][j][x ^ 1][y ^ 1] % mod * p[i + j] % mod)) % mod;

    std::cout << res << "\n";

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

