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

const int N = 2e5 + 10;
std::priority_queue<int> q;
int a[N];

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n && i <= k; i++)
        q.push(a[i]);
    n = std::min(n, k);
    while (m--)
    {
        int op;
        std::cin >> op;
        if (op == 1)
        {
            int x;
            std::cin >> x;
            if (n < k)
            {
                n++;
                q.push(x);
                continue;
            }
            if (x < q.top())
            {
                q.pop();
                q.push(x);
            }
        }
        else
        {
            if (n < k)
                std::cout << -1 << std::endl;
            else
                std::cout << q.top() << std::endl;
        }
    }
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}