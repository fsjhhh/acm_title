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
    int n, q;
    std::cin >> n;
    int l, r;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    l = a[0], r = a[n - 1];

    std::map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        if (l == a[i]) {
            mp2[a[i]] = a[i + 1];
        } else if (r == a[i]) {
            mp1[a[i]] = a[i - 1];
        } else {
            mp1[a[i]] = a[i - 1];
            mp2[a[i]] = a[i + 1];
        }
    }

    std::cin >> q;

    while (q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            if (x == r) {
                r = y;
                mp1[y] = x;
                mp2[x] = y;
            } else {
                mp1[y] = x;
                mp2[y] = mp2[x];
                mp1[mp2[x]] = y;
                mp2[x] = y;
            }
        } else {
            int x;
            std::cin >> x;
            if (x == l) {
                l = mp2[x];
                mp1.erase(mp1[x]);
                mp2.erase(x);
            } else if (r == x) {
                r = mp1[x];
                mp1.erase(x);
                mp2.erase(mp2[x]);
            } else {
                int ls = mp1[x], rs = mp2[x];
                mp2[ls] = rs;
                mp1[rs] = ls;
                mp1.erase(x);
                mp2.erase(x);
            }
        }
    }

    int x = l;
    while (x != r) {
        std::cout << x << " ";
        x = mp2[x];
    }

    std::cout << x << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
