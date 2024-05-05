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

LL calc(LL x) {
    auto s = std::to_string(x);
    int n = s.size();
    if (n < 11) {
        return 0;
    }
    std::vector dp(n, std::vector(11, std::vector(11, std::vector(2, std::vector(2, std::vector(2, std::vector<LL>(2, -1)))))));
    auto dfs = [&](auto self, int pos, int ls_1, int ls_2, bool is_limit, bool is_zero, bool is_same, bool four, bool eight) -> LL {
        if (four && eight) {
            return 0;
        }
        if (pos == n) {
            if (is_same) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dp[pos][ls_1][ls_2][is_limit][is_same][four][eight] != -1) {
            return dp[pos][ls_1][ls_2][is_limit][is_same][four][eight];
        }

        LL ans = 0;
        for (int i = 0; i <= (is_limit ? s[pos] - '0' : 9); i++) {
            if (is_zero && i == 0) {
                continue;
            } else {
                ans += self(self, pos + 1, ls_2, i + 1, is_limit && i == s[pos] - '0', false, is_same || (!is_zero && ls_1 == ls_2 && ls_2 == i + 1), four || (i == 4), eight || (i == 8));
            }
        }
        dp[pos][ls_1][ls_2][is_limit][is_same][four][eight] = ans;
        return ans;
    };

    return dfs(dfs, 0, 0, 0, true, true, false, false, false);

}

void solve() {
    LL l, r;
    std::cin >> l >> r;

    std::cout << calc(r) - calc(l - 1) << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
