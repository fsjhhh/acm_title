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
    int h, w, q;
    std::cin >> h >> w >> q;
    std::vector<std::array<int, 3>> a(q);
    int mx = 0;
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> a[i][j];
        }
        mx = std::max(mx, a[i][2]);
        a[i][1] -- ;
    }

    std::vector<int> row(h, 0), col(w, 0);
    int r = 0, c = 0;
    std::vector<LL> ans(mx + 1, 0);
    ans[0] = 0;

    for (int i = q - 1; i >= 0; i--) {
        if (a[i][0] == 1) {
            if (!row[a[i][1]]) {
                ans[a[i][2]] += (w - c);
                r ++ ;
                row[a[i][1]] = 1;
            }
        } else {
            if (!col[a[i][1]]) {
                ans[a[i][2]] += (h - r);
                c ++ ;
                col[a[i][1]] = 1;
            }
        }

    }

    LL sum = 0, cnt = 0;
    for (int i = 1; i <= mx; i++) {
        sum += ans[i];
        cnt += (ans[i] != 0);
    }

    ans[0] = 1ll * h * w - sum;
    cnt += (ans[0] != 0);

    std::cout << cnt << "\n";
    for (int i = 0; i <= mx; i++) {
        if (ans[i]) {
            std::cout << i << " " << ans[i] << "\n";
        }
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
