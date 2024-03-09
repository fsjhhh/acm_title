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
// #include <bits/stdc++.h>
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
    std::vector<int> a(n);
    std::map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mp2[a[i]] ++ ;
    }

    int mex1 = 0, mex2 = 0;
    for (int i = 0; i < n; i++) {
        if (mp2[mex2]) {
            mex2 ++ ;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        mp1[a[i]] ++ ;
        mp2[a[i]] -- ;
        while (mp1[mex1]) {
            mex1 ++ ;
        }
        if (!mp2[a[i]] && a[i] < mex2) {
            mex2 = a[i];
        }

        if (mex1 == mex2) {
            std::cout << "2\n";
            std::cout << 1 << " " << i + 1 << "\n";
            std::cout << i + 2 << " " << n << "\n";
            return ;
        }

    }

    std::cout << "-1\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
