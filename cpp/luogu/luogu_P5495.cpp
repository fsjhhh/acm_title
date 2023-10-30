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

const int N = 2e7 + 10;
#define uint unsigned int
uint seed, n;
uint a[N];

bool st[N];

inline uint getnext()
{
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed;
}

void solve()
{
    std::cin >> n >> seed;
    LL mod = 4294967296;
    for (int i = 1; i <= n; i++)
        a[i] = getnext();

    st[1] = true;
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            for (int j = 1; i * j <= n; j++)
            {
                a[i * j] = a[j] + a[i * j];
                st[i * j] = true;
            }
        }
    }

    uint ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans ^ a[i]);
    }
    std::cout << ans << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}