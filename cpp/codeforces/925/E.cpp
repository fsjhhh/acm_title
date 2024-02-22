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
    int n, m;
    std::cin >> n >> m;
    std::vector<PII> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        int cnt = 0, num = 0;
        bool ok = false;
        while (x) {
            int z = x % 10;
            if (z == 0) {
                if (!ok) {
                    cnt ++ ;
                }
                num ++ ;
            } else {
                ok = true;
                num ++ ;
            }
            x /= 10;
        }
        a[i] = {num, cnt};
    }

    std::sort(a.begin(), a.end(), [&](PII x, PII y) -> bool {
        if (x.second == y.second) {
            return x.first > y.first;
        }
        return x.second > y.second;
    });

    int ans = 0;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (!ok) {
            ans += (a[i].first - a[i].second);
        } else {
            ans += a[i].first;
        }
        ok = !ok;
    }

    std::cout << (ans > m ? "Sasha" : "Anna") << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
