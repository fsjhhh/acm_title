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
    int n, t;
    std::cin >> n >> t;
    std::map<LL, LL> mp1, mp2;
    mp1[0] = n;
    for (int i = 0; i < n; i++) {
        mp2[i] = 0;
    }
    for (int i = 0; i < t; i++) {
        int a, b;
        std::cin >> a >> b;
        a -- ;
        mp1[mp2[a]] -- ;

        if (mp1[mp2[a]] == 0) {
            mp1.erase(mp2[a]);
        }

        mp2[a] += b;
        mp1[mp2[a]] ++ ;
        std::cout << mp1.size() << "\n";
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
