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
    LL x;
    std::cin >> x;
    x -- ;
    std::vector<LL> a, z;
    std::vector<LL> cf(65);
    cf[0] = 1;
    for (int i = 1; i <= 62; i++) {
        cf[i] = cf[i - 1] * 2;
    }

    LL w = 1, sum = 0;
    while (x) {
        while (x >= cf[w]) {
            x -= cf[w];
            a.push_back(w);
            w ++ ;
        }
        while (x < cf[w]) {
            w -- ;
        }
        if (!w) {
            break;
        }
        x -= cf[w];
        a.push_back(w);
    }
    std::cout << a.size() << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
