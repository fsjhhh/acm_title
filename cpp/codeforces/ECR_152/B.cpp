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

const int N = 3e5 + 10;
std::pair<int, LL> a[N];

bool cmp(std::pair<int, LL> x, std::pair<int, LL> y)
{
    if (x.second == y.second)
        return x.first < y.first;
    return x.second > y.second;
}

void solve()
{
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) {
        int x;
        std::cin >> x;
        x %= k;
        if (x == 0)
            x = k;
        a[i] = {i, x};
    }
    
    std::sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i ++ ) {
        std::cout << a[i].first << " \n"[i == n];
    }

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