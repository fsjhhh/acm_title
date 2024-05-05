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
    int n;
    std::cin >> n;
    std::vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (x >= 0) {
            a.push_back(x);
        } else {
            b.push_back(x);
        }
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int ans = 0;
    if (n % 2 == 0) {
        if (b.size() % 2 == 1) {
            ans = b.back() * a[0];
            for (int i = 1; i < b.size() - 1; i += 2) {
                ans += b[i] * b[i - 1];
            }
            for (int i = 2; i < a.size(); i += 2) {
                ans += a[i] * a[i - 1];
            }
            std::cout << ans << "\n";
            return ;
        } else {
            for (int i = 1; i < b.size(); i += 2) {
                ans += b[i] * b[i - 1];
            }
            for (int i = 1; i < a.size(); i += 2) {
                ans += a[i] * a[i - 1];
            }
            std::cout << ans << "\n";
            return ;
        }
    } else {
        if (b.size() % 2 == 1) {
            for (int i = 1; i < b.size() - 1; i += 2) {
                ans += b[i] * b[i - 1];
            }
            for (int i = 1; i < a.size(); i += 2) {
                ans += a[i] * a[i - 1];
            }
            std::cout << ans << "\n";
            return ;
        } else {
            for (int i = 1; i < b.size(); i += 2) {
                ans += b[i] * b[i - 1];
            }
            for (int i = 2; i < a.size(); i += 2) {
                ans += a[i] * a[i - 1];
            }
            std::cout << ans << "\n";
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
