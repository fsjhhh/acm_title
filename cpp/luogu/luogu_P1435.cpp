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

std::string s1, s2;
int f[1010][1010];

void solve()
{
    std::cin >> s1;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        s2 += s1[n - i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s1[i] == s2[j])
                f[i + 1][j + 1] = f[i][j] + 1;
            else
                f[i + 1][j + 1] = std::max(f[i][j + 1], f[i + 1][j]);
        }
    }
    std::cout << n - f[n][n] << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}