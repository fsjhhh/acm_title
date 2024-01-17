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
    std::string s;
    std::cin >> s;
    int a = 0, c = 0, e = 0, p = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a ++ ;
        } else if (s[i] == 'C') {
            c ++ ;
        } else if (s[i] == 'E') {
            e ++ ;
        } else if (s[i] == 'P') {
            p ++ ;
        } else if (s[i] == 'T') {
            t ++ ;
        }
    }

    int ans = std::min({a, c / 2, e, p, t});
    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
