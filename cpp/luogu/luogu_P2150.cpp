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

void solve() {
    LL n, p;
    std::cin >> n >> p;
    
    std::vector<PLL> a(n + 1);
    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

    for (int i = 2; i <= n; i++) {
        a[i].first = i;
        for (int j = 0; j < 8; j++) {
            while (a[i].first % primes[j] == 0) {
                a[i].first /= primes[j];
                a[i].second |= (1 << j);
            }
        }
    }

    std::sort(a.begin() + 2, a.end());

    std::vector dp((1 << 8), std::vector<LL>(1 << 8));
    std::vector f1((1 << 8), std::vector<LL>(1 << 8));
    std::vector f2((1 << 8), std::vector<LL>(1 << 8));

    f1[0][0] = 1;

    for (int i = 2; i <= n; i++) {
        if (a[i].first == 1 || a[i].first != a[i - 1].first) {
            for (int s1 = (1 << 8) - 1; s1 >= 0; s1--) {
                int tmp = ((1 << 8) - 1) ^ s1;
                for (int s2 = tmp; s2 >= 0; s2--) {
                    LL res = ((f1[s1][s2] + f2[s1][s2]) % p - dp[s1][s2] + p) % p;
                    dp[s1][s2] = f1[s1][s2] = f2[s1][s2] = res;
                }
            }
        }

        int z = a[i].second;
        for (int s1 = (1 << 8) - 1; s1 >= 0; s1--) {
            int tmp = ((1 << 8) - 1) ^ s1;
            for (int s2 = tmp; s2 >= 0; s2--) {
                if (!(z & s2)) {
                    f1[s1 | z][s2] = (f1[s1 | z][s2] + f1[s1][s2]) % p;
                }
                if (!(z & s1)) {
                    f2[s1][z | s2] = (f2[s1][s2 | z] + f2[s1][s2]) % p;
                }
            }
        }
    }

    LL ans = 0;
    for (int s1 = ((1 << 8) - 1); s1 >= 0; s1--) {
        int tmp = ((1 << 8) - 1) ^ s1;
        for (int s2 = tmp; ; s2 = (s2 - 1) & tmp) {
            ans = (ans + ((f1[s1][s2] + f2[s1][s2]) % p - dp[s1][s2] + p) % p) % p;
            if (!s2) {
                break;
            }
        }
        // ans = (ans + ((f1[s1][0] + f2[s1][0]) % p - dp[s1][0] + p) % p) % p;
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
