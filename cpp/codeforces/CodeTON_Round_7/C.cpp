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
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n), b(n);
    std::vector<PII> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        v[i] = {a[i], i};
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::sort(v.begin(), v.end(), [&](PII x, PII y) -> bool {
        if (x.first == y.first) {
            return x.second < y.second;
        }
        return x.first > y.first;
    });
    std::sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        if (i < x) {
            if (v[x - i - 1].first <= b[i]) {
                std::cout << "NO\n";
                return ;
            }
        } else {
            if (v[n - i - 1 + x].first > b[i]) {
                std::cout << "NO\n";
                return ;
            }
        }
    }

    std::cout << "YES\n";
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        if (i < x) {
            c[v[x - i - 1].second] = b[i];
        } else {
            c[v[n - i - 1 + x].second] = b[i];
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << c[i] << " \n"[i == n - 1];
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
