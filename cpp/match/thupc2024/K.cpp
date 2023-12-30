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
std::vector<std::string> mp(5);

bool check(int x, int y) {
    if (x + 3 < 5) {
        if (mp[x + 1][y] == 'o' && mp[x + 2][y] == 'o' && mp[x + 3][y] == 'o') {
            return true;
        }
    }
    if (y + 3 < 5) {
        if (mp[x][y + 1] == 'o' && mp[x][y + 2] == 'o' && mp[x][y + 3] == 'o') {
            return true;
        }
    }
    if (x + 1 < 5 && y + 1 < 5) {
        if (mp[x + 1][y] == 'o' && mp[x][y + 1] == 'o' && mp[x + 1][y + 1] == 'o') {
            return true;
        }
    }
    return false;
}

void solve() {
    for (int i = 0; i < 5; i++) {
        std::cin >> mp[i];
    }

    int sum = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (mp[i][j] == 'o') {
                sum ++ ;
            }
        }
    }

    if (sum == 2) {
        std::cout << "Far\n";
    } else if (sum == 1 || sum == 3) {
        std::cout << "Away\n";
    } else {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (mp[i][j] == 'o') {
                    if (check(i, j)) {
                        std::cout << "Away\n";
                    } else {
                        std::cout << "Far\n";
                    }
                    return ;
                }
            }
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
