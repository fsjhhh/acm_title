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
    std::vector mp(n + 1, std::vector<int>(n + 1, 0));

    int q;
    std::cin >> q;
    while (q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int a;
            char b;
            std::cin >> a >> b;
            for (int i = 1; i <= n; i++) {
                mp[a][i] = b - 'a';
            }
        } else if (op == 2) {
            int a;
            char b;
            std::cin >> a >> b;
            for (int i = 1; i <= n; i++) {
                mp[i][a] = b - 'a';
            }
        } else if (op == 3) {
            int a;
            char b;
            std::cin >> a >> b;
            for (int i = 1; i <= n; i++) {
                if (a - i > 0 && a - i <= n) {
                    mp[i][a - i] = mp[a - i][i] = b - 'a';
                }
            }
        } else if (op == 4) {
            int a;
            char b;
            std::cin >> a >> b;
            for (int i = 1; i <= n; i++) {
                if (a + i > 0 && a + i <= n) {
                    mp[a + i][i] = b - 'a';
                }
            }
        } else {
            int a;
            std::cin >> a;
            for (int i = 1; i <= n; i++) {
                std::cout << (char)(mp[a][i] + 'a');
            }
            std::cout << "\n";
        }
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
