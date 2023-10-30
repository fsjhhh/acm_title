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
//priority_queue 优先队列
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
    LL a, b;
    std::cin >> a >> b;
    LL ans = 0;
    while (a != b)
    {
        if (a < b)
        {
            ans += (b - 1) / a;
            b -= (b - 1) / a * a;       
        }
        else
        {
            ans += (a - 1) / b;
            a -= (a - 1) / b * b;
        }
    }   
    std::cout << ans << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}