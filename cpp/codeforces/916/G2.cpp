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
#include <random>
#include <chrono>
// #include <bits/stdc++.h>
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef unsigned long long ULL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());


const LL mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> v(n + 1);

    std::vector<LL> ha(n + 1);
    for (int i = 1; i <= n; i++) {
        ha[i] = rng();
    }

    n *= 2;
    std::vector<int> a(n);
    std::vector<LL> f(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        v[a[i]].push_back(i);
        f[i + 1] = f[i] ^ ha[a[i]];
    }

    std::vector<PII> ed;
    for (int i = 0; i < n; i++) {
        int m = v[a[i]].back();
        int j;
        for (j = i; j <= m; j++) {
            if (v[a[j]].back() >= m) {
                m = v[a[j]].back();
            }
        }
        ed.push_back({i, j - 1});
        i = j - 1;
    }

    std::cout << ed.size() << " ";

    std::map<LL, int> mp;
    for (int i = 0; i <= n; i++) {
        mp[f[i]] = i;
    }

    LL cnt = 1;
    for (auto [l, r] : ed) {
        LL z = 1;
        for (int i = l + 1; i <= r; i++) {
            z ++ ;
            i = mp[f[i]];
        }
        cnt = (cnt * z) % mod;
    }

    std::cout << cnt << "\n";


}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
