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

int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
std::map<char, int> d = {{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}};

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    s = " " + s;
    std::vector<PLL> pre(n + 2);
    pre[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        auto [x, y] = pre[i - 1];
        x += dx[d[s[i]]], y += dy[d[s[i]]];
        pre[i] = {x, y};
    }

    std::vector<std::set<PLL>> v(6 * n + 10);
    for (int i = 0; i <= n; i++) {
        auto [x, y] = pre[i];
        v[x + 3 * n].insert({y, i});
    }

    for (int i = 0; i <= 4 * n; i++) {
        v[i].insert({INFL, INFL});
    }

    while (q -- ) {
        int tx, ty, l, r;
        std::cin >> tx >> ty >> l >> r;
        int px, py;

        px = tx, py = ty;
        auto [y1, idx1] = *v[px + 3 * n].lower_bound({py, 0});
        if (y1 == py && idx1 <= l - 1) {
            std::cout << "YES\n";
            continue;
        }

        auto [adx, ady] = pre[l - 1];
        auto [bdx, bdy] = pre[r];
        px = bdx + adx - tx, py = bdy + ady - ty;

        auto [y2, idx2] = *v[px + 3 * n].lower_bound({py, l - 1});
        if (y2 == py && idx2 >= l - 1 && idx2 <= r) {
            std::cout << "YES\n";
            continue;
        }

        px = tx, py = ty;
        auto [y3, idx3] = *v[px + 3 * n].lower_bound({py, r + 1});
        if (y3 == py && idx3 > r && idx3 <= n) {
            std::cout << "YES\n";
            continue;
        }

        std::cout << "NO\n";

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
