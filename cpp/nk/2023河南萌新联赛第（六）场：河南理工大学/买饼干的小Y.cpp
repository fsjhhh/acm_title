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
    int n, m;
    std::cin >> n >> m;
    LL cnt = 0;
    std::vector<int> v;
    v.push_back(m);
    while (m != 1) {
        m = (m + 1) / 2;
        v.push_back(m);
    }
    std::vector<LL> sum(v.size() + 1, 0);
    for (int i = 1; i <= v.size(); i ++ ) {
        sum[i] = sum[i - 1] + v[i - 1];
        if (sum[i] >= n) {
            std::cout << i - 1 << "\n";
            return ;
        }
    }
    n -= sum[v.size()];
    std::cout << v.size() + n - 1 << "\n";
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