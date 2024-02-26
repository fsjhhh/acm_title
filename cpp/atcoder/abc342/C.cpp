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
#include <bits/stdc++.h>
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
    std::string s;
    std::cin >> s;

    std::vector<int> f(26);
    std::iota(f.begin(), f.end(), 0);

    int q;
    std::cin >> q;
    
    while (q -- ) {
        char a, b;
        std::cin >> a >> b;
        for (int i = 0; i < 26; i++) {
            if (f[i] == a - 'a') {
                f[i] = b - 'a';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        s[i] = f[s[i] - 'a'] + 'a';
    }

    std::cout << s << '\n';

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
