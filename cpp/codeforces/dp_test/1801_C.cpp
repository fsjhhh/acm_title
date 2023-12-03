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

const int N = 2e5 + 10;
int tr[N];

int lowbit(int x) {
    return x & (-x);
}

void modify(int u, int x) {
    for (int i = u; i < N; i += lowbit(i)) {
        tr[i] = std::max(tr[i], x);
    }
}

int query(int u) {
    int res = 0;
    for (int i = u; i; i -= lowbit(i)) {
        res = std::max(res, tr[i]);
    }
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            std::cin >> x;
            if (!a[i].size() || x > a[i].back()) {
                a[i].push_back(x);
            }
        }
    }

    int ans = 0;
    std::sort(a.begin(), a.end(), [&](std::vector<int>& x, std::vector<int>& y) -> bool {
        return x.back() < y.back();
    });

    for (int i = 0; i < n; i++) {
        int dp = a[i].size();
        for (int j = 0; j < (int)a[i].size(); j++) {
            dp = std::max(dp, (int)a[i].size() - j + query(a[i][j] - 1));
        }
        ans = std::max(ans, dp);
        modify(a[i].back(), dp);
    }

    std::cout << ans << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = a[i].back(); j < N; j += lowbit(j)) {
            tr[j] = 0;
        }
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
