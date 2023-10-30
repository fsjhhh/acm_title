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

std::vector<int> v;

void solve()
{
    v.clear();
    int n, m;
    std::cin >> n >> m;
    for (int i = 2; i <= n; i += 2)
        v.push_back(i);
    for (int i = 1; i <= n; i += 2)
        v.push_back(i);

    for (int i = 0; i < n; i ++ )
        for (int j = 1; j <= m; j ++ )
            std::cout << (v[i] - 1) * m + j << " \n"[j == m];

    std::cout << "\n";

}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
