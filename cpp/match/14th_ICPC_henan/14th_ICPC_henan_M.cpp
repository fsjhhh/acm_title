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
// priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1010;
int a[N][N], b[N], f[N][N], s[N];

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        std::cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        a[y][++s[y]] = x;
    }
    for (int i = 1; i <= m; i++)
        std::sort(a[i] + 1, a[i] + s[i] + 1, std::greater<int>());
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= s[i]; j++)
        {
            a[i][j] += a[i][j - 1];
            if (j == 1)
                a[i][j] -= b[i];
        }
    }
    for (int i = 1; i <= k; i++)
        f[0][i] = -INF;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            f[i][j] = f[i - 1][j];
            for (int x = 0; x <= s[i]; x++)
            {
                if (j >= x)
                {
                    f[i][j] = std::max(f[i][j], f[i - 1][j - x] + a[i][x]);
                }
            }
        }
    }
    std::cout << f[m][k] << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}