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
LL f[N], a[N];
LL v, n;

void solve()
{
    std::cin >> v >> n;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i];

    for (int i = 1; i <= n; i ++ )
    	for (int j = v; j >= a[i]; j -- )
    		f[j] = std::max(f[j], f[j - a[i]] + a[i]);

    std::cout << v - f[v] << "\n";

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

