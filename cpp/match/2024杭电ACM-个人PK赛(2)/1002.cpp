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

struct Comb {
    LL n;
    std::vector<LL> _fac, _invfac, _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(LL n) : Comb() {
        init(n);
    }

    void init(LL m) {
        m = std::min(m, mod - 1);
        if (m <= n) {
            return ;
        }
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (LL i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i % mod;
        }

        _invfac[m] = inv(_fac[m]);
        for (LL i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i % mod;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }

        n = m;

    }

    LL get_fac(LL m) { // m的阶层
        if (m > n) {
            init(2 * m);
        }
        return _fac[m];
    }

    LL get_invfac(LL m) { // m的阶层的逆元
        if (m > n) {
            init(2 * m);
        }
        return _invfac[m];
    }

    LL get_inv(LL m) { // m的逆元
        if (m > n) {
            init(2 * m);
        }
        return _inv[m];
    }

    LL binom(LL n, LL m) { // C(n, m);
        if (n < m || m < 0) {
            return 0;
        }
        LL res = get_fac(n) * get_invfac(m) % mod * get_invfac(n - m) % mod;
        return res;
    }

} comb;

void solve() {
    LL n, m;
    std::cin >> n >> m;

    if (n == 1 || m == 1) {
        std::cout << "1\n";
        return ;
    }

    std::vector<PLL> pr;
    LL ans = 1;
    for (LL i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            LL cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt ++ ;
            }
            pr.push_back({i, cnt});
            (ans *= ((power(cnt + 1, m) - power(cnt, m)) % mod + mod) % mod) %= mod;
        }
    }

    if (n != 1) {
        pr.push_back({n, 1});
        (ans *= ((power(2, m) - 1) % mod + mod) % mod) %= mod;
    }
    
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
