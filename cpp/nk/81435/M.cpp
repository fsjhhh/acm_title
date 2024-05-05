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

const LL mod = 1e9 + 7;

LL calc(std::string& s) {
    int n = s.size();

    std::vector dp(n, std::vector(3 * 100, std::vector(n, std::vector(2, std::vector<int>(2, -1)))));

    auto dfs = [&](auto self, int pos, LL cnt0, LL cnt1, bool is_limit, bool is_zero) -> int {
        if (pos == n) {
            return (cnt1 >= 3 && std::abs(cnt0 - 200) >= 1);
        }
        if (dp[pos][cnt0][cnt1][is_zero][is_limit] != -1) {
            return dp[pos][cnt0][cnt1][is_zero][is_limit];
        }
        LL ans = 0;
        for (int i = 0; i <= (is_limit ? s[pos] - '0' : 9); i++) {
            if (is_zero && i == 0) {
                ans += self(self, pos + 1, cnt0, cnt1, is_limit && i == s[pos] - '0', true);
                ans %= mod;
            } else {
                ans += self(self, pos + 1, cnt0 + (i == 0 ? -1 : 0) + (i == 1 ? 1 : 0), (cnt1 >= 3 ? cnt1 : cnt1 + (i == 3 ? 1 : -cnt1)), is_limit && i == s[pos] - '0', false);
                ans %= mod;
            }
        }
        dp[pos][cnt0][cnt1][is_zero][is_limit] = ans;
        return ans;
    };

    return dfs(dfs, 0, 200, 0, true, true);

}

void solve() {
    std::string l, r;
    std::cin >> l >> r;

    auto check = [&](std::string& s) -> bool {
        int cnt0 = 0, cnt1 = 0;
        bool ok = false;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '1') {
                cnt1 ++ ;
            }
            if (s[i] == '0') {
                cnt0 ++ ;
            }
            if (i >= 2) {
                if (s[i] == '3' && s[i - 1] == '3' && s[i - 2] == '3') {
                    ok = true;
                }
            }
        }

        return (ok && std::abs(cnt0 - cnt1) >= 1);
    };

    std::cout << (calc(r) - calc(l) + mod + check(l)) % mod << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
