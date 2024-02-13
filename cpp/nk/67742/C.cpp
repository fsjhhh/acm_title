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

#define int long long
const int N = 2e5 + 10, M = 31 * N;
int ma[M][2], a[N], idx, sum[M];
int n, k;

const int mod = 1e9 + 7;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int power(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

int inv(int x, int p) {
    return power(x, p - 2, p);
}

void init(int n) {
    idx = 0;
    for (int i = 0; i <= 31 * n; i++) {
        ma[i][0] = ma[i][1] = 0;
        sum[i] = 0;
    }
}

void add_s(int x, int id) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!ma[p][u]) {
            ma[p][u] = ++ idx;
        }
        p = ma[p][u];
        sum[p] = (sum[p] + inv(power(2, id))) % mod;
    }
}

int find_s(int x) {
    int res = 0;
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1, v = k >> i & 1;
        if (v == 0) {
            if (!ma[p][u]) {
                return res;
            }
            p = ma[p][u];
        } else {
            if (ma[p][u]) {
                res = (res + sum[ma[p][u]]) % mod;
            }
            if (!ma[p][!u]) {
                return res;
            } else {
                p = ma[p][!u];
            }
        }
    }
    return (res + sum[p]) % mod;
}

void solve() {
    init(n);
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int z = find_s(a[i]);
        add_s(a[i], i + 1);
        z = (z * power(2, i)) % mod;
        ans = (ans + z + 1) % mod;
    }

    std::cout << ans << "\n";

}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
