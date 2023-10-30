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
int a[N];
int q[N], p[N];

void solve()
{
    memset(q, 0, sizeof q);
    memset(p, 0, sizeof p);
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i];
    for (int i = 1; i <= n; i ++ )
    {
        if (a[i] == a[1])
            q[i] = q[i - 1] + 1;
        else
            q[i] = q[i - 1];
    }
    for (int i = n; i >= 1; i -- )
    {
        if (a[i] == a[n])
            p[i] = p[i + 1] + 1;
        else
            p[i] = p[i + 1];
    }
    if (a[1] == a[n])
    {
        if (q[n] >= k)
        {
            std::cout << "Yes" << "\n";
            return ;
        }
    }
    for (int i = 1; i <= n; i ++ )
    {
        if (q[i] >= k && p[i] >= k)
        {
            std::cout << "Yes" << "\n";
            return ;
        }
    }
    std::cout << "No" << "\n";
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