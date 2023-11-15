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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    if (n <= 2) {
        std::cout << "Yes\n";
        return ;
    } 
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]] ++ ;
        if (mp.size() > 2) {
            std::cout << "No\n";
            return ;
        }
    }
    if (mp.size() == 1) {
        std::cout << "Yes\n";
        return ;
    }
    std::vector<int> cnt;
    for (auto [x, y] : mp) {
        cnt.push_back(y);
    }
    if (abs(cnt[0] - cnt[1]) < 2) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
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
