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
#include <iomanip> // std::fixed std::setprecision(x) 保留x位小数
#include <array>
#include <bitset>
#include <functional>
#include <ranges>
//#include <bits/stdc++.h>
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    LL N, X, K;
    std::cin >> N >> X >> K;

    auto calc = [&](LL x, LL k, LL n) -> LL {
        if (k < 0) {
            return 0ll;
        }
        if (k >= 64) {
            return 0ll;
        }
        i128 num = (1ll << k), l = x;
        l = (l << k);
        i128 r = l + num - 1;
        if (l > n) {
            return 0ll;
        }
        LL res = std::min(r, (i128)n) - l + 1;
        return res;
    };
    
    LL ans = 0;
    if (K) {
        ans += calc(X, K, N);
    }

    while (X > 1 && K > 0) {
        K -- ;
        ans += calc((X ^ 1), K - 1, N);
        X /= 2;
    }

    if (X && K == 0) {
        ans ++ ;
    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

