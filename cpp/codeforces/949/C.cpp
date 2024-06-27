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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (std::count(a.begin(), a.end(), -1) == n) {
        for (int i = 0; i < n; i++) {
            std::cout << i % 2 + 1 << " \n"[i == n - 1];
        }
        return ;
    }

    for (int i = 0, j = -1; i <= n; i++) {
        if (i == n || a[i] != -1) {
            if (j == -1) {
                for (int k = i - 1; k >= 0; k--) {
                    a[k] = (a[k + 1] == 1 ? 2 : a[k + 1] / 2);
                }
            } else if (i == n) {
                for (int k = j + 1; k < n; k++) {
                    a[k] = (a[k - 1] == 1 ? 2 : a[k - 1] / 2);
                }
            } else {
                int l = j, r = i;
                while (l + 1 < r) {
                    if (a[l] > a[r]) {
                        a[l + 1] = (a[l] == 1 ? 2 : a[l] / 2);
                        l++;
                    } else {
                        a[r - 1] = (a[r] == 1 ? 2 : a[r] / 2);
                        r--;
                    }
                }
                if (a[l] != a[r] / 2 && a[r] != a[l] / 2) {
                    std::cout << "-1\n";
                    return ;
                }
            }
            j = i;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
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
