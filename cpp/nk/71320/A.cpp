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

const LL mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<LL> a(n);
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        (sum += a[i]) %= mod;
    }
    
    std::vector<int> A;
    auto get_A = [&]() -> void {
        A.push_back(1);
        for (int i = n; i >= 1; i--) {
            A.push_back(A.back() * i % mod);
        }
    };

    get_A();

    auto power = [&](LL x, LL y) -> LL {
        LL res = 1;
        while (y) {
            if (y & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    };

    std::vector<LL> z(n + 1);
    for (int i = 1; i <= n; i++) {
        z[i] = z[i]
    }

    auto inv = [&](LL x) -> LL {
        return power(x, mod - 2);
    };

    for (int i = 1; i <= n; i++) {
        
    }

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
