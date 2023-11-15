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
    std::vector<std::string> cnt;
    std::vector<std::array<std::vector<std::string>, 10>> v(10);
    for (int i = 0; i < 10; i++) {
        cnt.push_back(std::to_string(i));
        v[1][i].push_back(std::to_string(i));

    }
    for (int i = 2; i < 10; i++) {
         for (int j = 1; j < 10; j++) {
             for (int k = 0; k < j; k++) {
                 std::string z = std::to_string(j);
                 for (auto it : v[i - 1][k]) {
                     cnt.push_back(z + it);
                     v[i][j].push_back(z + it);
                 }
             }
         }
    }
    cnt.push_back("9876543210");

    int n;
    std::cin >> n;
    std::cout << cnt[n] << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

