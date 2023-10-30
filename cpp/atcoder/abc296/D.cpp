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

typedef __int128 LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

long long a, b;

void solve()
{  


    std::cin >> a >> b;
    LL n = a, m = b;
    if (n * n < m) {
        std::cout << -1 << "\n";
        return ;
    }
    if (n >= m) {
        std::cout << b << "\n";
        return ;
    }

    while (1) {
        for (LL i = sqrt(m); i >= 1; i -- ) {
            if (i > n)
                continue;
            if (m / i > n)
                break;
            if (m % i == 0) {
                if (i <= n && m / i <= n) {
                    b = m;
                    std::cout << b << "\n";
                    return ;
                }
                else
                    break;
            }
        }
        m ++ ;
    }
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}