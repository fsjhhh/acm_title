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

std::vector<int> cnt = {0, 0, 1};

void solve() {
    LL a, b;
    std::cin >> a >> b;
    if (a > b) {
        std::swap(a, b);
    }

    LL ans = std::min(b - a, a);
    a -= ans;
    
    if ((a - 1) % 3 == 0) {
        ans += cnt[1];
        ans += 2 * (a - 1) / 3;
    } else if ((a - 2) % 3 == 0) {
        ans += cnt[2];
        ans += (a - 2) / 3 * 2;
    } else {
        ans += cnt[0];
        ans += a / 3 * 2;
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
