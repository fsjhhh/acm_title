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
    int n, k;
    std::cin >> n >> k;
    int x = 1, cnt = 0;
    while (x <= k) {
        x *= 2;
        cnt ++ ;
    }

    std::vector<int> a;
    a.push_back(k - x / 2);
    a.push_back(k + 1);
    a.push_back(k + 1 + x / 2);

    int w = 1;
    for (int i = 0; i < 20; i++, w *= 2) {
        if (w == x / 2) {
            continue;
        }
        a.push_back(w);
    }

    std::cout << a.size() << "\n";
    for (auto it : a) {
        std::cout << it << " ";
    }
    std::cout << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
