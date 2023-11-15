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
    int n, m;
    std::cin >> n >> m;
    std::string s1, s2;
    std::cin >> s1 >> s2;
    bool pd1 = false;
    for (int i = 1; i < n; i++) {
        if (s1[i] == s1[i - 1]) {
            pd1 = true;
            break;
        }
    }
    if (!pd1) {
        std::cout << "Yes\n";
        return ;
    }
    
    bool pd2 = false;
    for (int i = 1; i < m; i++) {
        if (s2[i] == s2[i - 1]) {
            pd2 = true;
            break;
        }
    }
    if (pd2) {
        std::cout << "No\n";
        return ;
    }

    for (int i = 1; i < n; i++) {
        if (s1[i] == s1[i - 1]) {
            if (s1[i - 1] == s2[0] || s1[i] == s2[m - 1]) {
                std::cout << "No\n";
                return ;
            }
        }
    }

    std::cout << "Yes\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
