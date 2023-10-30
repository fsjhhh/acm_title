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

const int N = 110;
int a[N];

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    int z = a[1], t = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i] == z) {
            t = i;
        }
    }
    if (t == n) {
        std::cout << -1 << "\n";
    }
    else {
        std::cout << t << " " << n - t << "\n";
        for (int i = 1; i <= t; i ++ ) {
            std::cout << a[i] << " \n"[i == t];
        }
        for (int i = t + 1; i <= n; i ++ ) {
            std::cout << a[i] << " \n"[i == n];
        }
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
