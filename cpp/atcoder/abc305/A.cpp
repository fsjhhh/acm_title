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

int f[25];

void solve()
{
    int z = 0;
    for (int i = 1; i <= 21; i ++ ) {
        f[z] = 1;
        z += 5;
    }
    int n;
    std::cin >> n;
    int q = n, p = n;
    for (int i = n; i <= 100; i ++ ) {
        if (f[i]) {
            q = i;
            break;
        }
    }
    for (int i = n; i >= 0; i -- ) {
        if (f[i]) {
            p = i;
            break;
        }
    }
    if (abs(n - q) > abs(n - p)) {
        std::cout << p << "\n";
    }
    else {
        std::cout << q << "\n";
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