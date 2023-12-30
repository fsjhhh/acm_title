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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto calc = [&]() -> int {
        int w = 0;
        int ls = INF, z = a[0], ans = 0;
        bool pd = false;
        for (int i = 1; i < n; i++) {
            if (a[i] > ls) {
                pd = true;
                break;
            }
            if (a[i] < a[i - 1]) {
                if (a[i] > z) {
                    pd = true;
                    break;
                }
                ls = z;
                z = a[i];
                w ++ ;
            }
            if (w >= 2) {
                pd = true;
                break;
            }
            if (ls != INF) {
                ans ++ ;
            }
        }

        ls = -1, z = a[0], w = 0;
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] < ls) {
                if (pd) {
                    return -1;    
                } else {
                    return ans;
                }
            }
            if (a[i] > a[i - 1]) {
                if (a[i] < z) {
                    if (pd) {
                        return -1;
                    } else {
                        return ans;
                    }
                }
                ls = z;
                z = a[i];
                w ++ ;
            }
            if (w >= 2) {
                if (pd) {
                    return -1;
                } else {
                    return ans;
                }
            }
            if (ls != -1) {
                res ++ ;
            }
        }

        return (pd ? res : (std::min(res, ans)));
    };

    int z1 = calc();
    std::reverse(a.begin(), a.end());

    int z2 = calc();
    if (z1 == -1 && z2 == -1) {
        std::cout << "-1\n";
    } else if (z1 == -1 && z2 != -1) {
        std::cout << z2 + 1 << "\n";
    } else if (z1 != -1 && z2 == -1) {
        std::cout << z1 << "\n";
    } else {
        std::cout << std::min(z1, z2 + 1) << "\n";
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
