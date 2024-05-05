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
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int mx = 0;
    std::vector<int> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = i;
    }


    int ans = -1;
    for (int b = 30; b >= 0; b--) {
        int t = (x >> b & 1);
        std::vector<int> v(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j <= r[i]; j++) {
                if (a[j] >> b & 1) {
                    cnt ++ ;
                }
            }
            v[i] = cnt;
            i = r[i];
            cnt = 0;
        }

        int sum = 0, w = 0;
        std::vector<int> R = r;
        for (int i = 0; i < n; i++) {
            if (sum == 0 && v[i] == 0) {
                i = R[i];
                continue;
            } else {
                if (sum == 0) {
                    w = i;
                }
                sum += v[i];
                if (sum % 2 == 0) {
                    R[w] = R[i];
                    sum = 0;
                }
                i = R[i];
            }
        }

        if (t) {
            if (!sum) {
                int res = 0;
                for (int i = 0; i < n; i++) {
                    res ++ ;
                    i = R[i];
                }
                ans = std::max(ans, res);
            }
        } else {
            if (sum) {
                std::cout << ans << "\n";
                return ;
            } else {
                r = R;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res ++ ;
        i = r[i];
    }

    std::cout << std::max(ans, res) << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
