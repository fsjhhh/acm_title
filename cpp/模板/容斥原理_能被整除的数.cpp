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
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 20;
LL p[N], n, m;

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
        std::cin >> p[i];

    LL res = 0;
    for (int i = 1; i < 1 << m; i++)
    {
        LL t = 1, cnt = 0;
        for (int j = 1; j <= m; j++)
        {
            if (i >> (j - 1) & 1)
            {
                if (t * p[j] > n)
                {
                    t = -1;
                    break;
                }
                cnt++;
                t *= p[j];
            }
        }

        if (t == -1)
            continue;

        if (cnt % 2)
            res += n / t;
        else
            res -= n / t;
    }

    std::cout << res << std::endl;
}

int main()
{
    int t = 1;
    while (t--)
        solve();
    return 0;
}