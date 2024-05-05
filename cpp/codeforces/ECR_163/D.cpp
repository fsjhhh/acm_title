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
    LL ans = 0;

    auto calc = [&](int len) -> bool {
        LL res = 0, cnt = 0;
        for (int i = n - len - 1; i >= 0; i--) {
            if (s[i] == s[i + len] || s[i] == '?' || s[i + len] == '?') {
                cnt ++ ;
            } else {
                cnt = 0;
            }
            if (cnt == len) {
                return true;
            }
        }
        return false;
    };

    for (LL i = (n / 2); i >= 1; i--) {
        if (calc(i)) {
            std::cout << i * 2 << "\n";
            return ;
        }
    }
    std::cout << "0\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
