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
int a[N], f[N];

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i];
    f[1] = 0, f[2] = abs(a[1] - a[2]);
    for (int i = 3; i <= n; i ++ )
    	f[i] = std::min(f[i - 2] + abs(a[i] - a[i - 2]), f[i - 1] + abs(a[i] - a[i - 1]));
    std::cout << f[n] << "\n";
}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

