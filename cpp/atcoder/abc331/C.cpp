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
    int n;
    std::cin >> n;
    std::vector<PII> a(n);
    std::map<int, LL> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
        mp[a[i].first] += a[i].first;
    }

    std::sort(a.begin(), a.end());

    std::vector<LL> sum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        sum[i] = sum[i + 1] + a[i].first;
    }

    std::vector<LL> ans(n);
    for (int i = 0; i < n; i++) {
        ans[a[i].second] = sum[i] - mp[a[i].first];
        mp[a[i].first] -= a[i].first;
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
