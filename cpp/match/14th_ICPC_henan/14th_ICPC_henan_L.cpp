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
char a[N][N];
int C[N][N], M[N][N], F[N][N];

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> a[i][j];
            if (a[i][j] == 'C')
                C[i][j]++;
            if (a[i][j] == 'M')
                M[i][j]++;
            if (a[i][j] == 'F')
                F[i][j]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            C[i][j] = (C[i][j] + C[i - 1][j] + C[i][j - 1] - C[i - 1][j - 1]);
            M[i][j] = (M[i][j] + M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1]);
            F[i][j] = (F[i][j] + F[i - 1][j] + F[i][j - 1] - F[i - 1][j - 1]);
        }
    }

    while (k--)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        int nc = C[x2][y2] - C[x1 - 1][y2] - C[x2][y1 - 1] + C[x1 - 1][y1 - 1];
        int nm = M[x2][y2] - M[x1 - 1][y2] - M[x2][y1 - 1] + M[x1 - 1][y1 - 1];
        int nf = F[x2][y2] - F[x1 - 1][y2] - F[x2][y1 - 1] + F[x1 - 1][y1 - 1];
        std::cout << nc << " " << nm << " " << nf << std::endl;
    }
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}