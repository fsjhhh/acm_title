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

const LL mod = 1e9 + 7;

void solve() {
    LL n, x, y, z;
    std::cin >> n >> x >> y >> z;
    auto power = [&](LL a, LL b) -> LL {
        LL res = 1;
        while (b) {
            if (b & 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };

    auto inv = [&](LL a) {
        return power(a, mod - 2);
    };

    auto C = [&](LL a, LL b) -> LL {
        LL fz = 1, fm = 1;
        for (LL i = 0; i < b; i++) {
            fz = fz * (a - i) % mod;
        } 
        for (LL i = 1; i <= b; i++) {
            fm = fm * i % mod;
        }
        int inv_fm = inv(fm);
        return fz * inv_fm % mod;
    };
    LL ans = (power(2, n) - ((C(n, x) + C(n, y) + C(n, z)) % mod) + mod) % mod;
    std::cout << ans - 1 << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
