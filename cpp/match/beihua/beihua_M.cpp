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

const int N = 110;
int a[N];

bool cmp(int a, int b)
{
    return a > b;
}

void solve()
{
    int n;
    std::string s;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> s >> a[i];
    }

    std::sort(a + 1, a + n + 1, cmp);
    LL res = 0;
    for (int i = 1; i <= std::min(n, 9); i++)
    {
        res += a[i];
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