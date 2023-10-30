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

void solve()
{
    LL n;
    std::cin >> n;
    LL i = 0, m = 0, s = 0;
    while (s < n)
    {
    	i += 1;
    	m += i;
    	s += m;
    }
    s = 0;
    std::cout << i << "\n";
    for (LL j = 1; j <= i; j ++ )
    {
    	LL h = std::min((n - s) / (i - j + 1), j);
    	std::cout << h << " \n"[j == i];
    	s += h * (i - j + 1);
    }
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

