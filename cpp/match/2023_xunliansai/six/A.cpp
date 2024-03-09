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

void solve() {
    std::string s;
    std::cin >> s;
    
    std::map<char, int> mp;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        int x;
        std::cin >> c >> x;
        mp[c] = x;
    }

    std::vector<int> cnt(26, 0);

    int ans = 0;
    for (auto it : s) {
        if (mp[it]) {
            if (cnt[it - 'a'] == 0) {
                ans += 2;
                cnt[it - 'a'] = (cnt[it - 'a'] + 2) % mp[it];
            } else {
                ans ++ ;
                cnt[it - 'a'] = (cnt[it - 'a'] + 1) % mp[it];
            }
        } else {
            ans ++ ;
        }
    }

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
