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
    std::vector<LL> f = {0, 1};
    while (1) {
        if (f.back() > 1e9) {
            break;
        }
        LL z = f[(int)f.size() - 1] + f[(int)f.size() - 2];
        f.push_back(z);
    }

    std::map<LL, std::array<LL, 3>> mp;
    for (int i = 0; i < (int)f.size(); i++) {
        for (int j = 0; j < (int)f.size(); j++) {
            for (int k = 0; k < (int)f.size(); k++) {
                mp[f[i] + f[j] + f[k]] = {f[i], f[j], f[k]};
            }
        }
    }

    int q;
    std::cin >> q;
    while (q -- ) {
        LL n;
        std::cin >> n;
        if (mp.find(n) != mp.end()) {
            std::cout << mp[n][0] << " " << mp[n][1] << " " << mp[n][2] << "\n";
        } else {
            std::cout << "-1\n";
        }
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
