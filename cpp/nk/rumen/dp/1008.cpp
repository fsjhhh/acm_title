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

const int N = 30;
bool st[N][N];
LL f[N][N];

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};

void solve()
{
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    n++, m++, x++, y++;
    st[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx > 0 && tx <= n && ty > 0 && ty <= m)
            st[tx][ty] = true;
    }
    f[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (st[i][j])
                continue;
            if (!st[i - 1][j])
                f[i][j] += f[i - 1][j];
            if (!st[i][j - 1])
                f[i][j] += f[i][j - 1];
        }
    }
    std::cout << f[n][m] << "\n";
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}