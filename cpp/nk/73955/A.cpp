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
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]] ++ ;
    }
    
    auto calc = [&](int x) -> int {
        int ans = 0;
        for (int i = 0; i < 62; i++) {
            if (x >> i & 1) {
                ans ++ ;
            }
        }
        return ans;
    };

    std::vector<PLL> b(mp.begin(), mp.end());
    int ans = 0;
    for (int i = 0; i < (int)b.size(); i++) {
        int cnt = calc(b[i].first), res = 0;
        for (int j = 0; j < (int)b.size(); j++) {
            res = (res + std::__gcd(b[i].first, b[j].first) * b[j].second % mod) % mod;
        }
        ans = (ans + cnt * res * b[i].second % mod) % mod;
    }

    std::cout << 2 * ans % mod << "\n";

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
