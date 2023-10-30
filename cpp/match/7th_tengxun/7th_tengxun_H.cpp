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

std::priority_queue<PLL, std::vector<PLL>, std::greater<PLL>> p;

void solve()
{
    LL n, m;
    std::cin >> n >> m;
    for (LL i = 1; i <= n; i++)
    {
        LL x;
        std::cin >> x;
        p.push({x, i});
    }
    LL ans = 1, res;
    while (1)
    {
        PLL t = p.top();
        p.pop();
        if (ans % 2 == 0)
        {
            if (!p.size())
            {
                res = t.first;
                break;
            }
        }
        else
        {
            t.first += m;
            p.push(t);
        }
        ans++;
    }
    std::cout << res << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}