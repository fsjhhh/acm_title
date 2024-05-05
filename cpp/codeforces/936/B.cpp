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

const LL mod = 1e9 + 7;

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
    int n, k;
    std::cin >> n >> k;
    std::vector<LL> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    LL sum = 0, mx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (sum < 0) {
            sum = a[i];
        } else {
            sum += a[i];
        }

        if (sum > mx) {
            mx = sum;
        }

        ans += a[i];

    }

    ans = (ans % mod + mod) % mod;
    mx = (mx % mod + mod) % mod;
    LL t = mx;

    ans = (ans + (power(2, k) - 1) * mx % mod) % mod;

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
