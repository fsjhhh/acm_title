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
    LL n, s, k;
    std::cin >> n >> s >> k;
    if (k == 0) {
        for (int i = 0; i < n - 1; i++) {
            std::cout << "1 ";
        }
        std::cout << s - (n - 1) << "\n";
        return ;
    }
    if (n < 2 * k + 1) {
        std::cout << "-1\n";
        return ;
    }

    if (n == 2 * k + 1) {
        LL x = (s - k) / (k + 1);
        LL w = s - x * (k + 1);
        LL y = w / k, p = w % k;
        if (x < y + 1) {
            std::cout << "-1\n";
            return ;
        }
        std::vector<int> ans(n);
        for (int i = 0; i < n; i += 2) {
            ans[i] = x;
        }
        int cnt = 0;
        for (int i = 1; i < n; i += 2) {
            if (cnt < p) {
                ans[i] = y + 1;
            } else {
                ans[i] = y;
            }
            cnt ++ ;
        }
        for (int i = 0; i < n; i++) {
            std::cout << ans[i] << " \n"[i == n - 1];
        }
        return ;
    }

    LL z = n - (2 * k + 1);
    LL sum = 3 * k + 2 + z;
    if (s < sum) {
        std::cout << "-1\n";
        return ;
    }
    
    LL w = s - sum;
    std::vector<int> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(2);
        ans.push_back(1);
    }
    ans.push_back(2);
    for (int i = 0; i < z; i++) {
        ans.push_back(1);
    }

    ans[2 * k + 1] += w;
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
