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

const int N = 1e5 + 10;
std::vector<std::vector<int>> d(N);

void init() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            d[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    std::vector<std::vector<int>> c(N);
    for (int i = 0; i < n; i++) {
        for (auto it : d[a[i]]) {
            c[it].push_back(n - i - 1);
        }
    }

    std::vector<LL> f(N), g(N);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < (int)c[i].size(); j++) {
            f[i] += c[i][j] * j;
        }
    }

    LL ans = 0;
    for (int i = N - 1; i >= 1; i--) {
        g[i] = f[i];
        for (int j = i * 2; j < N; j += i) {
            g[i] -= g[j];
        }
        ans += g[i] * i;
    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    init();
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
