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

typedef unsigned long long LL;
typedef unsigned long long ULL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const LL mod = 1e9 + 7;
std::vector<LL> pow2(65, 1);

void solve() {
    LL l, r;
    std::cin >> l >> r;
    LL ans = 0;
    auto power = [&](LL x, LL y) -> ULL {
        ULL res = 1;
        while (y) {
            if (y & 1) {
                res = res * x;
            }
            x = x * x;
            y >>= 1;
        }
        return res;
    };
    LL l_1, r_1;
    for (LL i = 0; i < 64; i++) {
        if (pow2[i] > l) {
            l_1 = i - 1;
            break;
        }
    }
    for (LL i = 0; i < 64; i++) {
        if (pow2[i] > r) {
            r_1 = i - 1;
            break;
        }
    }

    for (int i = l_1; i <= r_1; i++) {
        LL L = std::max((ULL)l, power(2, i)), R = std::min((ULL)r, power(2, i + 1) - 1);
        LL l_2 = 0, r_2 = 0, t_1 = 1, t_2 = 1;
        while (t_1 * i <= L) {
            t_1 *= i;
            l_2 ++ ;
        }
        while (t_2 * i <= R) {
            t_2 *= i;
            r_2 ++ ;
        }

        for (int j = l_2; j <= r_2; j++) {
            LL p = std::max((ULL)L, power(i, j)), q = std::min((ULL)R, power(i, j + 1) - 1);
            ans = (ans + (q - p + 1) * j) % mod;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    pow2[1] = 2;
    for (int i = 2; i < 64; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }
    while (t -- )
        solve();
    return 0;
}
