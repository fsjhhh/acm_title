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

const int N = 210;
char a[N][N];
bool st[N][N];
int n, m;

int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

void bfs1(int x, int y)
{
    std::queue<PII> q;
    q.push({x, y});
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        int x1 = t.first, y1 = t.second;
        for (int i = 0; i < 4; i++)
        {
            int tx = x1 + dx[i], ty = y1 + dy[i];
            if (!st[tx][ty] && (tx > 0 && tx <= n && ty > 0 && ty <= m) && a[tx][ty] == '.')
            {
                q.push({tx, ty});
                st[tx][ty] = true;
            }
        }
    }
}

int bfs2(int x, int y)
{
    std::queue<PII> q;
    q.push({x, y});
    int tmp = 0;
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        int x1 = t.first, y1 = t.second;
        for (int i = 0; i < 4; i++)
        {
            int tx = x1 + dx[i], ty = y1 + dy[i];
            if (!st[tx][ty] && (tx > 0 && tx <= n && ty > 0 && ty <= m))
            {
                if (a[tx][ty] == '.')
                {
                    bfs1(tx, ty);
                    tmp++;
                }
                if (a[tx][ty] == '#')
                {
                    q.push({tx, ty});
                    st[tx][ty] = true;
                }
            }
        }
    }
    return tmp;
}

void solve()
{
    while (std::cin >> n >> m)
    {
        memset(st, false, sizeof st);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                std::cin >> a[i][j];
        bfs1(1, 1);
        int A = 0, B = 0, C = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == '#' && !st[i][j])
                {
                    int tmp = bfs2(i, j);
                    if (tmp == 0)
                        C++;
                    if (tmp == 1)
                        A++;
                    if (tmp == 2)
                        B++;
                }
            }
        }
        std::cout << A << " " << B << " " << C << std::endl;
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
