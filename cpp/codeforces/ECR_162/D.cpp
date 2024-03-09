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
    std::vector<LL> a(n + 2), sum(n + 1), L(n + 1), R(n + 2);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            L[i] = L[i - 1];
        } else {
            L[i] = i;
        }
    }

    for (int i = n; i >= 1; i--) {
        if (a[i] == a[i + 1]) {
            R[i] = R[i + 1];
        } else {
            R[i] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        int ans = INF;
        if (i > 1) {
            if (a[i - 1] > a[i]) {
                ans = std::min(ans, 1);
            } else if (L[i - 1] != 1) {
                int l = 1, r = L[i - 1] - 1;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    if (sum[i - 1] - sum[mid - 1] > a[i]) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                if (sum[i - 1] - sum[l - 1] > a[i]) {
                    ans = std::min(ans, i - l);
                }
            }
        }
        if (i < n) {
            if (a[i + 1] > a[i]) {
                ans = std::min(ans, 1);
            } else if (R[i + 1] != n) {
                int l = R[i + 1] + 1, r = n;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (sum[mid] - sum[i] > a[i]) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                if (sum[l] - sum[i] > a[i]) {
                    ans = std::min(ans, l - i);
                }
            }
        }
        if (ans == INF) {
            std::cout << "-1 ";
        } else {
            std::cout << ans << " ";
        }
    }

    std::cout << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
