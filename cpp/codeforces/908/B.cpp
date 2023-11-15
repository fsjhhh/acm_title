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
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]] ++ ;
    }

    bool pd = false;
    int cnt = 0;
    std::vector<int> z, st;
    for (auto [x, y] : mp) {
        std::cerr << x << " " << y << "\n";
        if (y >= 2) {
            z.push_back(x);
            st.push_back(0);
            cnt ++ ;
        }
    }

    if (cnt < 2) {
        std::cout << "-1\n";
        return ;
    }
    
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        if (a[i] == z[0]) {
            if (!st[0]) {
                b[i] = 2;
                st[0] ++ ;
            } else {
                b[i] = 1;
            }
            continue;
        }
        if (a[i] == z[1]) {
            if (!st[1]) {
                b[i] = 3;
                st[1] ++ ;
            } else {
                b[i] = 1;
            }
            continue;
        }
        b[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " \n"[i == n - 1];
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
