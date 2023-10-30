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

void solve() {
    std::string a, b, s;
    std::cin >> a >> b >> s;

    auto to_10 = [&](std::string x, int t) -> LL {
        LL res = 0;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] >= '0' && x[i] <= '9') {
                res = res * t + (x[i] - '0');
            } else {
                res = res * t + (x[i] - 'A' + 10);
            }
        }
        return res;
    };

    for (int i = 16; i >= 2; i--) {
        LL aa = to_10(a, i);
        LL bb = to_10(b, i);
        LL ss = to_10(s, i);
        if (aa + bb == ss) {
            std::cout << i << "\n";
            return ;
        }
    }
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
