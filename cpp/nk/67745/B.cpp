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

const LL N = 2e5 + 10, mod = 1e9 + 7;

void solve() {
    std::vector<LL> fb(N, 1);
    fb[1] = 2, fb[2] = 3;
    for (int i = 3; i < N; i++) {
        fb[i] = (fb[i - 1] + fb[i - 2]) % mod;
    }

    std::string s;
    std::cin >> s;
    int n = s.size();

    std::map<char, int> mp;
    mp['m'] = 0;
    mp['y'] = 1;
    mp['g'] = 2;
    mp['o'] = 3;

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'm') {
            std::vector<int> wz;
            auto dfs = [&](auto self, int u, int cnt) -> void {
                if (u >= n || mp[s[u]] != cnt) {
                    return ;
                }
                if (cnt == 3) {
                    wz.push_back(u);
                }
                for (int i = 1; i <= 2; i++) {
                    self(self, u + i, cnt + 1);
                }
            };
            dfs(dfs, i, 0);

            for (auto it : wz) {
                ans = (ans + fb[i] * fb[n - it - 1] % mod) % mod;
            }

        }
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
