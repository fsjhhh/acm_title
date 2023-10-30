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

char c;
int n, a;

int check(int x)
{
    int ans = 0;
    while (x)
    {
        if (a == x % 10)
            ans ++ ;
        x /= 10;
    }
    return ans;
}

void solve()
{
    std::cin >> c;
    std::cin >> n;
    if (c == '*' || c == '=' || c == ',')
    {
        std::cout << n * (n + 1) / 2 << std::endl;
        return ;
    }
    a = c - '0';
    LL ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= i; j ++ )
        {
            ans += (check(i) + check(j) + check(i * j));
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