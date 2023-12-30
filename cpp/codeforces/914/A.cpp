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
    LL a, b;
    std::cin >> a >> b;
    LL xq, yq, xh, yh;
    std::cin >> xq >> yq >> xh >> yh;
    std::vector<int> dx = {-1, -1, 1, 1}, dy = {-1, 1, 1, -1};
    LL ans = 0;
    std::map<PLL, int> mp_1, mp_2;
    for (int i = 0; i < 4; i++) {
        LL tx = xq + dx[i] * a, ty = yq + dy[i] * b;
        mp_1[{tx, ty}] = 1;
        tx = xq + dx[i] * b, ty = yq + dy[i] * a;
        mp_1[{tx, ty}] = 1;
    }

    for (int i = 0; i < 4; i++) {
        LL tx = xh + dx[i] * a, ty = yh + dy[i] * b;
        mp_2[{tx, ty}] = 1;
        tx = xh + dx[i] * b, ty = yh + dy[i] * a;
        mp_2[{tx, ty}] = 1;
    }

    for (auto [it, z] : mp_2) {
        ans += mp_1[it];
    }

    std::cout << ans << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
