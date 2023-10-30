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
    LL x;
    std::cin >> x;
    for (int i = -1000; i <= 1000; i++)
        for (int j = -1000; j <= 1000; j++)
        {
            if ((x - i * 11 - j * 45) % 14 == 0)
            {
                if (i < 0)
                    std::cout << 0 << " ";
                else
                    std::cout << i << " ";
                if (j < 0)
                    std::cout << 0 << " ";
                else
                    std::cout << j << " ";
                if (x - i * 11 - j * 45 < 0)
                    std::cout << 0 << std::endl;
                else
                    std::cout << std::abs(x - i * 11 - j * 45) / 14 << std::endl;
                if (i < 0)
                    std::cout << std::abs(i) << " ";
                else
                    std::cout << 0 << " ";
                if (j < 0)
                    std::cout << std::abs(j) << " ";
                else
                    std::cout << 0 << " ";
                if (x - i * 11 - j * 45 < 0)
                    std::cout << std::abs(x - i * 11 - j * 45) / 14 << std::endl;
                else
                    std::cout << 0 << std::endl;
                return;
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