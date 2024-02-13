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
// #include <bits/stdc++.h>
// priority_queue 优先队列
// std::cout.flush(); 交互题
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
    LL n, m;
    std::cin >> n >> m;
    std::vector<LL> v(n), w(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> v[i] >> w[i];
    } 

    LL ans = 0;
    auto check = [&](int x) -> void {
        LL res = 0;
        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (int j = x + 1; j < 63; j++) {
                if ((w[i] >> j & 1) && !(m >> j & 1)) {
                    ok = true;
                    break;
                }
            }
            if (x != -1 && w[i] >> x & 1) {
                ok = true;
            }
            if (!ok) {
                res += v[i];
            }
        }
        ans = std::max(ans, res);
    };

    for (int i = 0; i < 63; i++) {
        if (m >> i & 1) {
            check(i);
        }
    }

    check(-1);

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