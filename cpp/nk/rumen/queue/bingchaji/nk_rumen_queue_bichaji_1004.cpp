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

const int N = 1e5 + 10;
PII a[N];
std::priority_queue<int, std::vector<int>, std::greater<int>> q;
// std::queue<int> q;

bool cmp(PII a1, PII b1)
{
    return a1.second > b1.second;
}

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        a[i] = {x, y};
    }
    // std::sort(a + 1, a + n + 1, cmp);
    LL ans = 0, res = 0;
    for (int i = 1; i <= n; i++)
    {
        q.push(a[i].first);
        ans += a[i].first;
        while (q.size() > a[i].second)
        {
            ans -= q.top();
            // ans -= q.front();
            q.pop();
        }
        res = std::max(res, ans);
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