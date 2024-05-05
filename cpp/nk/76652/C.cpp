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

const LL mod = 998244353;
LL power(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

LL power(LL a, LL b, LL p) {
    LL res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

LL inv(LL x) {
    return power(x, mod - 2);
}

LL inv(LL x, LL p) {
    return power(x, p - 2, p);
}

void solve() {
    LL a, b, k;
    std::cin >> a >> b >> k;
    
    LL L2 = k * (k + 1) % mod * inv(2) % mod;
    LL L3 = (k * (k + 1) % mod * (2 * k + 1) % mod * inv(6) % mod + L2) % mod * inv(2) % mod;
    LL L4 = (((L2 * L2) % mod * 2 % mod + (k * (k + 1) % mod * (2 * k + 1) % mod * inv(6) % mod) * 3 % mod + L2) % mod * inv(6) % mod + L3) % mod * inv(2) % mod;

    LL ans1 = (a * k % mod + b) % mod;
    LL ans2 = (a * L2 % mod + b * k % mod) % mod;
    LL ans3 = (a * L3 % mod + b * L2 % mod) % mod;
    LL ans4 = (a * L4 % mod + b * L3 % mod) % mod;

    std::cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
