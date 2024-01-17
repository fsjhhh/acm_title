// 洛谷P2602

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
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

LL calc(LL x, int dight) {
    auto s = std::to_string(x);
    int n = s.size();
    std::vector dp(n, std::vector(n, std::vector(2, std::vector<LL>(2, -1))));
    auto dfs = [&](auto self, int pos, LL cnt, bool is_limit, bool is_zero) -> LL {
        if (pos == n) {
            return cnt;
        }
        if (dp[pos][cnt][is_zero][is_limit] != -1) {
            return dp[pos][cnt][is_zero][is_limit];
        }
        LL ans = 0;
        for (int i = 0; i <= (is_limit ? s[pos] - '0' : 9); i++) {
            if (is_zero && i == 0) {
                ans += self(self, pos + 1, cnt, is_limit && i == s[pos] - '0', true);
            } else {
                ans += self(self, pos + 1, cnt + (i == dight), is_limit && i == s[pos] - '0', false);
            }
        }
        dp[pos][cnt][is_zero][is_limit] = ans;
        return ans;
    };

    return dfs(dfs, 0, 0, true, true);

}

void solve() {
    LL l, r;
    std::cin >> l >> r;
    for (int i = 0; i < 10; i++) {
        std::cout << calc(r, i) - calc(l - 1, i) << " \n"[i == 9];
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

