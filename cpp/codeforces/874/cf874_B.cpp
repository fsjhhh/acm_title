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
int a[N], b[N], c[N];
PII p[N];

void solve()
{
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        p[i] = {a[i], i};
    }
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];
    std::sort(p + 1, p + n + 1);
    std::sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        c[p[i].second] = b[i];
    for (int i = 1; i <= n; i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}