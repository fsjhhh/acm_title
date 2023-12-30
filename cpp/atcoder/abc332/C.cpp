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
    std::string s;
    std::cin >> s;
    int tx = 0, wr = m;
    int ans = 0;
    int tx_z = 0, wr_z = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (wr == 0) {
                if (tx == 0) {
                    ans ++ ;
                    tx_z ++ ;
                } else {
                    tx -- ;
                    tx_z ++ ;
                }
            } else {
                wr -- ;
                wr_z ++ ;
            }
        } else if (s[i] == '2') {
            if (tx == 0) {
                ans ++ ;
                tx_z ++ ;
            } else {
                tx -- ;
                tx_z ++ ;
            }
        } else {
            tx += tx_z;
            wr += wr_z;
            tx_z = 0;
            wr_z = 0;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
