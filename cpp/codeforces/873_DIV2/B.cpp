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

const int N = 1e5 + 10;
int a[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void solve()
{
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        std::cin >> x;
        x = abs(x - i);
        if (i == 1)
        {
            ans = x;
            continue;
        }
        ans = gcd(ans, x);
    }
    std::cout << ans << "\n";
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