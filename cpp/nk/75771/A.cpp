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
    int x, n;
    std::cin >> x >> n;

    char c;
    int w = 0;
    for (int i = 0; i < n; i++) {
        char z;
        int y;
        std::cin >> z >> y;
        if (w < y) {
            c = z;
            w = y;
        }
    }

    std::string s;
    if ((x + w - 1) / w > 1000) {
        std::cout << "-1\n";
    } else {
        for (int i = 0; i < (x + w - 1) / w; i++) {
            std::cout << c;
        }
        std::cout << "\n";
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
