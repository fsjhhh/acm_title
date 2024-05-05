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
    LL n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    std::vector<std::vector<int>> pos(26);

    for (int i = 0; i < (int)s.size(); i++) {
        pos[s[i] - 'a'].push_back(i);
    }

    auto check = [&](LL x) -> bool {
        if (x == 0) {
            return true;
        }

        LL ls = 0, p = 0, g = x;
        bool ok = false;
        for (int i = 0; i < (int)t.size() && ls <= n; i += (ok ? 1 : 0)) {
            ok = false;
            if (!pos[t[i] - 'a'].size()) {
                return false;
            }
            if (p == 0) {
                int cnt = (int)pos[t[i] - 'a'].size();
                LL cost = g / cnt;
                ls += cost;
                g -= cost * cnt;
                LL mod = g % cnt;
                if (mod) {
                    ls += 1;
                    p = (pos[t[i] - 'a'][mod - 1] + 1) % s.size();
                    g -= mod;
                } else {
                    p = (pos[t[i] - 'a'].back() + 1) % s.size();
                }
            } else {
                int it = std::lower_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), p) - pos[t[i] - 'a'].begin();
                int cnt = pos[t[i] - 'a'].size() - it;
                if (g > cnt) {
                    g -= cnt;
                    p = 0;
                } else {
                    p = (pos[t[i] - 'a'][g + it - 1] + 1) % s.size();
                    g = 0;
                }
            }
            if (g == 0) {
                g = x;
                ok = true;
            }
        }

        return ls <= n;

    };

    LL l = 0, r = INFL;
    while (l < r) {
        LL mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    std::cout << l << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
