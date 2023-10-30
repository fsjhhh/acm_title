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
    double k1 = ((67 - 40) * 1.0) / ((35 - 41) * 1.0);
    double b1 = (40.0 - 41.0 * k1);
    double k2 = ((80 - 55) * 1.0) / ((47 - 61) * 1.0);
    double b2 = (80.0 - 47.0 * k2);
    int a, b;
    while (std::cin >> a >> b)
    {
        if ((a >= 58 && a <= 93) && (b >= 4 && b <= 37))
            std::cout << "Inazuma" << std::endl;
        else
        {
            double t1 = a * k1 + b1;
            double t2 = a * k2 + b2;
            if (t1 >= b)
                std::cout << "Sumeru" << std::endl;
            if (t2 <= b)
                std::cout << "Mondstadt" << std::endl;
            if (t1 <= b && t2 >= b)
                std::cout << "Liyue" << std::endl;
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