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

std::priority_queue<LL, std::vector<LL>, std::greater<LL>> q;

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        q.push(x);
    }

    LL res = 0;
    while (q.size() != 1)
    {
        LL x = q.top();
        q.pop();
        LL y = q.top();
        q.pop();
        res += (x + y);
        q.push(x + y);
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