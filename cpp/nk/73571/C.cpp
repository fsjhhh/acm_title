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
    LL a, b, c;
    std::cin >> a >> b >> c;

    auto power = [&](LL x, LL y) -> LL {
        LL res = 1;
        while (y) {
            if (y & 1) {
                res = res * x;
            }
            y >>= 1;
            x = x * x;
        }
        return res;
    };

    auto C = [&](LL a, LL b) -> LL {
        LL s = 1, x = 1;
        for (int i = 1; i <= a; i++) {
            s *= i;
            x *= (b - i + 1);
        }
        LL res = x / s;
        return res;
    };

    LL q_z_s = power(a, 12);
    LL q_z_x = power(16, 12);
    
    LL z = C(12, 16);

    LL h_z_x = power(16, 4);
    LL h_z_s = power(a, 4) + z * power(b, 4) + z * power(c, 4);
    double ans = ((q_z_s * 1.0) / (q_z_x * 1.0)) * ((h_z_s * 1.0) / (h_z_x * 1.0));
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
