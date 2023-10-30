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

const int N = 10;
std::string s[N];
int a[N];
bool st[N];
int n, m;

bool dfs(int u)
{
    if (u > n)
        return true;

    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            if (u == 1)
            {
                a[u] = i;
                st[i] = true;
                if (dfs(u + 1))
                {
                    return true;
                }
                else
                {
                    st[i] = false;
                }
            }
            else
            {
                int cnt = 0;
                for (int j = 0; j < m; j++)
                {
                    if (s[a[u - 1]][j] != s[i][j])
                        cnt++;
                }
                if (cnt == 1)
                {
                    a[u] = i;
                    st[i] = true;
                    if (dfs(u + 1))
                    {
                        return true;
                    }
                    else
                    {
                        st[i] = false;
                    }
                }
            }
        }
    }
    return false;
}

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> s[i];
    if (dfs(1))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
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