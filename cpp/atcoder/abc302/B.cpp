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

const int N = 110;
std::string s[N];
int n, m;

char d[] = {'0', 'n', 'u', 'k', 'e'};

bool pd(int x, int y)
{
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; i++)
    {
        bool p = false;
        for (int j = 1; j <= 4; j++)
        {
            if (x + dx[i] * j < 0 || x + dx[i] * j >= n || y + dy[i] * j < 0 || dy[i] * j >= m || s[x + dx[i] * j][y + dy[i] * j] != d[j])
            {
                p = true;
                break;
            }
        }
        if (!p)
        {
            std::cout << x + 1 << " " << y + 1 << std::endl;
            for (int j = 1; j <= 4; j++)
            {
                std::cout << x + 1 + dx[i] * j << " " << y + 1 + dy[i] * j << std::endl;
            }
            return true;
        }
    }
    return false;
}

void solve()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        std::cin >> s[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 's')
            {
                if (pd(i, j))
                {
                    return;
                }
            }
        }
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