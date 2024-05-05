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
    std::map<char, char> mp;
    mp['4'] = 'a';
    mp['6'] = 'b';
    mp['c'] = 'c';
    mp['d'] = 'd';
    mp['3'] = 'e';
    mp['f'] = 'f';
    mp['9'] = 'g';
    mp['h'] = 'h';
    mp['i'] = 'i';
    mp['j'] = 'j';
    mp['k'] = 'k';
    mp['1'] = 'l';
    mp['m'] = 'm';
    mp['n'] = 'n';
    mp['0'] = 'o';
    mp['p'] = 'p';
    mp['q'] = 'q';
    mp['r'] = 'r';
    mp['5'] = 's';
    mp['7'] = 't';
    mp['u'] = 'u';
    mp['v'] = 'v';
    mp['w'] = 'w';
    mp['x'] = 'x';
    mp['y'] = 'y';
    mp['2'] = 'z';

    std::string s;
    while (std::cin >> s) {
        for (int i = 0; i < s.size(); i++) {
            if (!mp[s[i]]) {
                std::cout << s[i];
            } else {
                std::cout << mp[s[i]];
            }
        }
        std::cout << " ";
    }
    std::cout << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
