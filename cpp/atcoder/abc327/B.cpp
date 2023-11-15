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

    auto power = [&](LL x, LL y) -> LL {
        LL res = 1;
        while (y) {
            if (y & 1) {
                res = res * x;
            }
            x = x * x;
            y >>= 1;
        }
        return res;
    };
 
    std::vector<LL> a(20);
    for (int i = 1; i < 20; i++) {
        a[i] = power(i, i);
    }
    LL B;
    std::cin >> B;
    for (int i = 1; i < 20; i++) {
        if (a[i] == B) {
            std::cout << i << "\n";
            return ;
        }
    }
    std::cout << -1 << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
