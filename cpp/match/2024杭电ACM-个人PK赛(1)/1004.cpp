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
    std::string s;
    std::cin >> s;
    
    int cnt0 = 0, cnt1 = 0;
    bool pd = false;

    std::vector<PII> pos;
    for (int i = 0; i < (int)s.size(); i++) {
        if (!pd) {
            if (s[i] == '1') {
                pd = true;
                cnt1 ++ ;
            }
            continue;
        }
        if (s[i] == '1') {
            pos.push_back({i, cnt0});
            cnt1 ++ ;
        } else {
            cnt0 ++ ;
        }
    }

    LL ans = 0;

    if (!pd) {
        std::cout << "1\n";
        return ;
    }

    for (auto [x, y] : pos) {
        int w = y + 1;
        ans = (ans + power(2, w) * (power(3, cnt0 + cnt1 - x - 1)) % mod) % mod;
    }

    ans = (ans + power(2, cnt0)) % mod;

    ans = (ans * 2ll) % mod;

    ans = (ans + 1ll * power(3, cnt0 + cnt1 - 1)) % mod;

    // for (int i = 1; i < s.size(); i++) {
    //     for (int j = 0; j < i; j++) {
    //         ans = (ans + comb.binom(i - 1, j) * power(2, j) % mod) % mod;
    //     }
    // }

    std::cout << ans << "\n";

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
