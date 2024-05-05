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
    std::string s;
    std::cin >> s;
    int n = s.size();

    std::string t = "leetcode";
    std::map<char, int> mp;
    mp['l'] = 1;
    mp['e'] = 2;
    mp['t'] = 3;
    mp['c'] = 4;
    mp['o'] = 5;
    mp['d'] = 6;
    
    std::set<int> se[7];
    for (int i = 0; i < n; i++) {
        if (mp[s[i]]) {
            se[mp[s[i]]].insert(i);
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (ok) {
            int w = 0;
            bool pd = false;
            int z = i;
            for (int j = 0; j < 8; j++) {
                auto it = se[mp[t[j]]].lower_bound(z);
                if (it == se[mp[t[j]]].end()) {
                    pd = true;
                    break;
                }
                z = (*it) + 1;
            }

            if (!pd) {
                std::cout << z << " ";
            } else {
                ok = true;
                std::cout << "0 ";
            }
        } else {
            std::cout << "0 ";
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
