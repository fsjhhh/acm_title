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

const int N = 2010;
int a[N];
LL f[N][N];

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
        std::cin >> a[i];

    for (int i = 1; i <= n; i ++ )
        f[i][i] = a[i] * n;

    for (int i = 2; i <= n; i ++ )
        for (int l = 1; l <= n; l ++ )
        {
            int r = l + i - 1;
            if (r > n)
                break;
            f[l][r] = std::max(f[l][r - 1] + a[r] * (n - i + 1), f[l + 1][r] + a[l] * (n - i + 1));
        }
    std::cout << f[1][n] << "\n";
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

