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
    std::vector<char> stk;
    int ans = 0, res = 0;
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a ++ ;
        }
        if (s[i] == 'B') {
            b ++ ;
        }
        if (s[i] == 'C') {
            c ++ ;
        }
        stk.push_back(s[i]);
        int w = stk.size();
        if ((w - d) >= 3) {
            if (stk[w - 1] != stk[w - 2] && stk[w - 1] != stk[w - 3] && stk[w - 2] != stk[w - 3]) {
                if (stk[w - 1] != 'D' && stk[w - 2] != 'D' && stk[w - 3] != 'D') {
                    if (res == 0) {
                        res ++ ;
                    }
                    a -- ;
                    b -- ;
                    c -- ;
                    stk.pop_back();
                    stk.pop_back();
                    stk.pop_back();
                    stk.push_back('D');
                    d ++ ;
                }
            }
        }
        if (a == b && b == c) {
            ans = std::max(ans, a + res);
            res = 0;
            a = 0;
            b = 0;
            c = 0;
            d = 0;
            stk.clear();
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
