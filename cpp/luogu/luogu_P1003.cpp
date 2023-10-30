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

const int N = 1e4 + 10;
int a[N], b[N], c[N], d[N];

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i] >> b[i] >> c[i] >> d[i];
    int x, y;
    std::cin >> x >> y;
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (x >= a[i] && y >= b[i] && x <= a[i] + c[i] && y <= b[i] + d[i])
            ans = i;
    }
    std::cout << ans << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}