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
    int t = 0;
    std::string ans;
    ans += s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] >= s[i - 1]) {
            t = i;
            ans += s[i];
        } else {
            break;
        }
    }

    bool ok = false;
    char ls = s[t];
    for (int i = t + 1; i < s.size(); i++) {
        if (ok) {
            ans += ls;
            continue;
        }
        if (s[i] <= ls) {
            ans += s[i];
            ls = s[i];
        } else {
            ans += ls;
            ok = true;
        }
    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
