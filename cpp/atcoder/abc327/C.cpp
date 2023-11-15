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
    std::vector mp(9, std::vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cin >> mp[i][j];
        }
    }
    
    for (int i = 0; i < 9; i++) {
        std::vector<bool> col(10, 0), row(10, 0);
        for (int j = 0; j < 9; j++) {
            col[mp[i][j]] = true;
            row[mp[j][i]] = true;
        }
        for (int j = 1; j < 10; j++) {
            if (!col[j]) {
                std::cout << "No\n";
                return ;
            }
            if (!row[j]) {
                std::cout << "No\n";
                return ;
            }
        }
    }
    
    std::vector<int> strat = {0, 3, 6}, end = {0, 3, 6};
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            int tx = strat[x], ty = end[y];
            std::vector<bool> sh(10, 0);
            for (int i = tx; i < tx + 3; i++) {
                for (int j = ty; j < ty + 3; j++) {
                    sh[mp[i][j]] = true;
                }
            }
            for (int i = 1; i < 10; i++) {
                if (!sh[i]) {
                    std::cout << "No\n";
                    return ;
                }
            }
        }
    }

    std::cout << "Yes\n";


}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
