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

class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        
        auto calc = [&](LL w) -> LL {
            std::string s;
            while(w) {
                s += (w % 2 + '0');
                w /= 2;
            }

            int n = s.size();

            std::vector dp(n, std::vector(n, std::vector(2, std::vector<LL>(2, -1))));
            auto dfs = [&](auto self, int pos, int cnt, bool is_limit, bool is_zero) -> LL {
                if (pos == -1) {
                    return cnt;
                }

                if (dp[pos][cnt][is_limit][is_zero] != -1) {
                    return dp[pos][cnt][is_limit][is_zero];
                }

                LL ans = 0;
                for (int i = 0; i <= (is_limit ? (s[pos] - '0') : 1); i++) {
                    if (is_zero && i == 0) {
                        ans += self(self, pos - 1, cnt, (is_limit && i == s[pos] - '0'), true);
                    } else {
                        ans += self(self, pos - 1, cnt + ((pos + 1) % x == 0 && i == 1), (is_limit && i == s[pos] - '0'), false);
                    }
                }

                dp[pos][cnt][is_limit][is_zero] = ans;
                return ans;

            };

            return dfs(dfs, n - 1, 0, true, true);
        };
        
        LL l = 1, r = (k + 1) << x;

        while (l < r) {
            LL mid = (l + r + 1) >> 1;
            if (calc(mid) <= k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

void solve() {
    Solution a_a;
    LL k;
    int x;
    std::cin >> k >> x;
    auto ans = a_a.findMaximumNumber(k, x);

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