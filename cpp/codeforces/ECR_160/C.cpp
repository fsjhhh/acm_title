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
    int q;
    std::cin >> q;
    std::vector<int> a(30, 0);
    while (q -- ) {
        LL op, x;
        std::cin >> op >> x;
        if (op == 1) {
            a[x] ++ ;
        } else {
            LL z = 0;
            bool pd = false;
            for (int i = 0; i < 30; i++) {
                z += a[i];
                int t = (x >> i & 1);
                if (z >= t) {
                    if (t == 1) {
                        z -- ;
                    }
                } else {
                    pd = true;
                    std::cout << "NO\n";
                    break;
                }
                z /= 2;
            }
            if (!pd) {
                std::cout << "YES\n";
            }
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
