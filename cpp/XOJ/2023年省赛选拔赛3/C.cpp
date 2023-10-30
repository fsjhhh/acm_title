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

const int N = 1e6 + 10;
LL a[N];

void solve()
{
    LL n, p;
    std::cin >> n >> p;
    for (int i = 1; i <= n; i ++ ) {
        std::cin >> a[i];
    }
    LL ans = 0;
    if (p % 2 == 1) {
        for (int i = 1; i <= n; i ++ ) {
            if (a[i] % 2) {
                ans ^= 1;
            }
            else {
                ans ^= 0;
            }
        }
    }
    else {
        for (int i = 1; i <= n; i ++ ) {
            LL t = (a[i] % (p + 1));
            if (t == p) {
                ans ^= 2;
            }
            else {
                if (t % 2) {
                    ans ^= 1;
                }
                else {
                    ans ^= 0;
                }
            }
        }
    }
    std::cout << (ans ? "GOOD" : "BAD") << "\n";
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