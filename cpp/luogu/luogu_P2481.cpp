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

const LL mod = 999911659;

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
    LL n, p;
    std::cin >> n >> p;
    LL sum = 1;
    std::vector<LL> g(p + 1);
    LL len_n = 0;
    if (n <= p) {
        sum = 0;
        for (int i = 1; i <= n; i++) {
            sum = (sum * 10 + 1) % p;
            g[sum] ++ ;
            len_n = sum;
        }
    } else {
        std::vector<int> a(p + 1);
        int len, ls;
        sum = 1 % p;
        for (int i = 1; i <= p + 1; i++) {
            if (a[sum]) {
                ls = a[sum];
                len = i - ls;
                break;
            } else {
                a[sum] = i;
                g[sum] ++ ;
                sum = (sum * 10 + 1) % p;
            }
        }

        for (int i = 0; i < p; i++) {
            if (a[i] && a[i] >= ls) {
                g[i] += (n - a[i]) / len % mod; 
                if ((a[i] - ls + 1) % len == (n - ls + 1) % len) {
                    len_n = i;
                }
            }
        }
    }

    std::vector dp(p + 1, std::vector(p + 1, std::vector<int>(11, 0)));
    dp[0][len_n][0] = 1;

    std::vector<int> inv(11);
    std::vector c(p + 1, std::vector<int>(11));
    inv[1] = 1;
    for (int i = 2; i < 9; i++) {
        inv[i] = (LL)(mod - mod / i) * inv[mod % i] % mod;
    }
    for (int i = 0; i < p; i++) { 
        c[i][0] = 1; 
        if (!g[i]) {
            continue;
        }
        for (int j = 1; j < 9; j++) { 
            c[i][j] = (LL)c[i][j - 1] * g[i] % mod * inv[j] % mod; 
            g[i] = (g[i] + 1) % mod;
        }
    }

    int idx = 0;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            for (int x = 0; x < 9; x++) {
                for (int y = 0; x + y < 9; y++) {
                    dp[i + 1][(j + y * i) % p][x + y] = ((LL)dp[i][j][x] * c[i][y] + dp[i + 1][(j + y * i) % p][x + y]) % mod;
                }
            }
        }
    }

    LL ans = 0;
    for (int i = 0; i < 9; i++) {
        ans = (ans + dp[p][0][i]) % mod;
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
