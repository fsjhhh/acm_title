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

const int N = 2e5 + 10;
LL a[N], b[N];

void solve()
{
	LL n, ans = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        std::cin >> a[i];
        if (i == 1)
            ans = a[i];
        else
            ans &= a[i];
    }
    if (ans != 0)
        std::cout << 1 << "\n";
    else
    {
        LL res = 0;
        b[1] = a[1];
        for (int i = 2; i <= n; i ++ )
        {
            if (b[i - 1] == 0)
            {
                b[i] = a[i];
                res ++ ;
            }
            else
            {
                b[i] = (b[i - 1] & a[i]);
            }
        } 
        if (b[n] == 0)
            res ++ ;
        std::cout << res << "\n";
    }
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

