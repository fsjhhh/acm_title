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

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 2), b(n + 2);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    std::vector<int> l(n + 2), r(n + 2), l_x(n + 2), r_x(n + 2);
    r[0] = 1, l[n + 1] = n;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            l[i] = 0;
            r[i] = i + 1;
            r_x[i] = 0;
            l_x[i] = i + 1;
        } else if (i == n) {
            l[i] = i - 1;
            r[i] = n + 1;
            r_x[i] = i - 1;
            l_x[i] = n + 1;
        } else {
            l[i] = i - 1;
            r[i] = i + 1;
            l_x[i] = i + 1;
            r_x[i] = i - 1;
        }
    }

    std::vector<int> w, die;
    for (int i = 1; i <= n; i++) {
        w.push_back(i);
    }
    int cnt = 0, num = 0;
    while (1) {
        std::vector<bool> st(n + 2);
        die.clear();
        for (auto i : w) {
            int z = a[l[i]] + a[r[i]];
            if (z > b[i]) {
                die.push_back(i);
                st[i] = true;
                num ++ ;
            }
        }
        w.clear();
        for (auto i : die) {
            r[r_x[i]] = r[i];
            l[l_x[i]] = l[i];
            l_x[l[i]] = l_x[i];
            r_x[r[i]] = r_x[i];
            if (!st[l[i]] && l[i] != 0) {
                w.push_back(l[i]);
                st[l[i]] = true;
            }
            if (!st[r[i]] && r[i] != n + 1) {
                w.push_back(r[i]);
                st[r[i]] = true;
            }
        }
        std::cout << num << " ";
        cnt ++ ;
        if (num == 0) {
            break;
        }
        num = 0;
    }
    for (int i = cnt; i < n; i++) {
        std::cout << 0 << " ";
    }
    std::cout << "\n";

}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
