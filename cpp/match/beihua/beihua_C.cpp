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

void solve()
{
    int n;
    std::string a, b, c;
    std::cin >> n >> a >> b >> c;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i] || b[i] != c[i] || b[i] != c[i])
        {
            if (a[i] == b[i])
            {
                res++;
            }
            else if (a[i] == c[i])
            {
                res++;
            }
            else if (b[i] == c[i])
            {
                res++;
            }
            else
            {
                res += 2;
            }
        }
    }

    std::cout << res << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}