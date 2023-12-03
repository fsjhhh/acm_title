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
    int n, s, m, l;
    LL ans = INFL;
    std::cin >> n >> s >> m >> l;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                if (6 * i + 8 * j + 12 * k >= n) {
                    LL w = (1ll * s * i + 1ll * m * j + 1ll * l * k);
                    ans = std::min(ans, w);
                }
            }
        }
    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
