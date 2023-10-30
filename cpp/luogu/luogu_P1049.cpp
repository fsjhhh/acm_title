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

const int N = 2e4 + 10;
int v[N], f[N];
int n, m;

void solve()
{
    std::cin >> m >> n;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> v[i];
    for (int i = 1; i <= n; i ++ )
    	for (int j = m; j >= v[i]; j -- )
    		f[j] = std::max(f[j], f[j - v[i]] + v[i]);
    std::cout << m - f[m] << "\n";
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

