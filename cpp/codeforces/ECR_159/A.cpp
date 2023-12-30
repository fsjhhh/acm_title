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
    LL _0 = 0, _1 = 0;
    bool pd = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            _0 ++ ;
        } else {
            _1 ++ ;
        }
        if (i > 0) {
            if ((s[i] == '0' && s[i - 1] == '1') || (s[i] == '1' && s[i - 1] == '0')) {
                pd = true;
            }
        }
    }

    if (_0 > _1 || pd) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
