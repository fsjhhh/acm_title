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
    std::vector<PLL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }

    std::sort(a.begin(), a.end());

    std::vector<LL> ans(n), s(n);
    ans[n - 1] = n;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            s[i] = a[i].first;
        } else {
            s[i] = s[i - 1] + a[i].first;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] >= a[i + 1].first) {
            ans[i] = ans[i + 1];
        } else {
            ans[i] = i + 1;
        }
    }
    
    std::vector<LL> res(n);
    for (int i = 0; i < n; i++) {
        res[a[i].second] = ans[i] - 1;
    }

    for (int i = 0; i < n; i++) {
        std::cout << res[i] << " \n"[i == n - 1];
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
