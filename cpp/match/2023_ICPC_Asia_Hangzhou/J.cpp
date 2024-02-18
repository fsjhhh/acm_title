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
    for (int i = 2; i <= n; i += 2) {
        std::cout << "? " << i << " " << i - 1 << std::endl;
        int x;
        std::cin >> x;
        if (x) {
            int u, v;
            if (i != 2) {
                u = 1, v = 2;
            } else {
                u = 3, v = 4;
            }
            std::cout << "? " << i - 1 << " " << u << std::endl;
            int t;
            std::cin >> t;
            if (t) {
                std::cout << "? " << i - 1 << " " << v << std::endl;
                int w;
                std::cin >> w;
                if (w) {
                    std::cout << "! 1" << std::endl;
                } else {
                    std::cout << "! 2" << std::endl;
                }
            } else {
                std::cout << "? " << i << " " << u << std::endl;
                int w;
                std::cin >> w;
                if (w) {
                    std::cout << "? " << i << " " << v << std::endl;
                    int e;
                    std::cin >> e;
                    if (e) {
                        std::cout << "! 1" << std::endl;
                    } else {
                        std::cout << "! 2" << std::endl;
                    }
                } else {
                    std::cout << "! 2" << std::endl;
                }
            }
            return ;
        }
    }

    if (n % 2) {
        std::cout << "? " << n - 1 << " " << n << "\n";
        int x, i = n;
        std::cin >> x;
        if (x) {
            int u, v;
            if (i != 2) {
                u = 1, v = 2;
            } else {
                u = 3, v = 4;
            }
            std::cout << "? " << i - 1 << " " << u << std::endl;
            int t;
            std::cin >> t;
            if (t) {
                std::cout << "? " << i - 1 << " " << v << std::endl;
                int w;
                std::cin >> w;
                if (w) {
                    std::cout << "! 1" << std::endl;
                } else {
                    std::cout << "! 2" << std::endl;
                }
            } else {
                std::cout << "? " << i << " " << u << std::endl;
                int w;
                std::cin >> w;
                if (w) {
                    std::cout << "? " << i << " " << v << std::endl;
                    int e;
                    std::cin >> e;
                    if (e) {
                        std::cout << "! 1" << std::endl;
                    } else {
                        std::cout << "! 2" << std::endl;
                    }
                } else {
                    std::cout << "! 2" << std::endl;
                }
            }
            return ;
        }
    }

    std::cout << "! 2" << std::endl;

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
