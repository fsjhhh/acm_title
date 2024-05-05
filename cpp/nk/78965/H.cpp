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

struct node {
    LL sw, st, en, id;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<node> a(n);

    for (int i = 0; i < n; i++) {
        LL x, y;
        std::cin >> x >> y;
        a[i].st = x, a[i].en = y;
        a[i].id = i;
        a[i].sw = 0;
    }

    std::vector<LL> ans(n);
    LL ls = -1, ed = 0;
    
    for (int i = 0; i < n; i++) {
        std::sort(a.begin(), a.end(), [&](node x, node y) -> bool {
            if ((i128)x.sw * (i128)y.en == (i128)y.sw * (i128)x.en) {
                if (x.st == y.st) {
                    return x.id < y.id;
                }
                return x.st < y.st;
            }
            return (i128)x.sw * (i128)y.en > (i128)y.sw * (i128)x.en;
        });

        if (ls == -1) {
            ls = a[0].st;
            ed = ls;
        }


        ans[a[0].id] = ed;

        ed += a[0].en;
        std::vector<node> b;
        bool ok = false;
        for (int j = 1; j < (int)a.size(); j++) {
            if (a[j].st > ed) {
                b.push_back(a[j]);
                b.back().sw = 0;
            } else {
                ok = true;
                b.push_back(a[j]);
                b.back().sw = ed - a[j].st;
            }
        }

        if (!ok) {
            ls = -1;
        }

        a = b;

    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << "\n";
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
