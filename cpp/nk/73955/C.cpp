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

std::map<int, std::string> mp = {
    {0, "Dragon"},
    {1, "Snake"},
    {2, "Horse"},
    {3, "Goat"},
    {4, "Monkey"},
    {5, "Rooster"},
    {6, "Dog"},
    {7, "Pig"},
    {8, "Rat"},
    {9, "Ox"},
    {10, "Tiger"},
    {11, "Rabbit"},
};

void solve() {
    LL n;
    std::cin >> n;
    if (n >= 0) {
        n %= 12;
        std::cout << mp[n] << "\n";
    } else {
        n = std::abs(n) % 12;
        n = (12 - n) % 12;
        std::cout << mp[n] << "\n";
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
