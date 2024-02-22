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
const int N = 2e6 + 10;
bool st[N];
std::vector<int> primes;

void get_primes() {
    int n = N - 1;
    for(int i = 2; i <= n; i++) {
        if(!st[i]) {
            primes.push_back(i);
        }
        for(int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<PLL> ed;
    for (int i = n; i > 0; i--) {
        auto it = std::upper_bound(primes.begin(), primes.end(), i);
        if (it == primes.end()) {
            std::cout << "-1\n";
            return ;
        }
        int z = *it;
        if (i + i >= z) {
            ed.push_back({z - i, i});
            i = z - i;
        } else {
            std::cout << "-1\n";
            return ;
        }
    }

    std::sort(ed.begin(), ed.end());

    std::vector<int> ans(n + 1);
    for (auto [x, y] : ed) {
        for (int i = 0; i <= (y - x); i++) {
            ans[x + i] = y - i;
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
    }

}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

