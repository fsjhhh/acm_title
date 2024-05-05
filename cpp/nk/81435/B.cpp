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

struct Mu{
    int N;
    std::vector<LL> preim;
    std::vector<LL> a, mu;
    Mu(int N) : a(N + 1), mu(N + 1) {
        mu[1] = 1;
        for (int i = 2; i <= N; i++) {
            if (!a[i]) {
                a[i] = i;
                mu[i] = -1;
                preim.push_back(i);
            }
            for (auto p : preim) {
                if (1ll * i * p > N) break;
                a[i * p] = p;
                if (p == a[i]) {
                    break;
                }
                mu[i * p] = -mu[i];
            }
        }
    }
};

Mu m(200000);

const LL mod = 1e9 + 7;

const int N = 1e5 + 5;

void solve() {
    LL n, x, y, z;
    std::cin >> n >> x >> y >> z;

    std::vector<LL> a(n + 1), cnt(N);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        cnt[a[i]] ++ ;
    }

    std::vector<LL> f(N + 1), g(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * i <= N; j++) {
            LL u = j * i;
            f[i] = (f[i] + cnt[u] * u % mod) % mod;
        }
        f[i] = f[i] * f[i] % mod;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * i <= N; j++) {
            g[i] = (g[i] + m.mu[j] * f[i * j] % mod + mod) % mod;
        }
    }

    LL ans = 0;
    for (int i = 1; i <= N; i++) {
        LL d = (1ll * i * x + y) / z;
        d %= mod;
        ans = (ans + d * g[i] % mod) % mod;
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
