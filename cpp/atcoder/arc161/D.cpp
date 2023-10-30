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
    LL n, d;
    std::cin >> n >> d;
    if (d * n > n * (n - 1) / 2)
    {
        std::cout << "No" << std::endl;
        return ;
    }  
    std::cout << "Yes" << std::endl;
    for (LL i = 1; i <= d; i ++ )
        for (LL j = 1; j <= n; j ++ )
            std::cout << j << " " << (j + i - 1) % n + 1 << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}