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

const LL mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<LL> sum(n + 1), dp(n);
    LL ans = 0;
    std::vector<int> stk;
    for (int i = 0; i < n; i++) {
        while (stk.size() && a[stk.back()] > a[i]) {
            ans = (ans - dp[stk.back()] + mod) % mod;
            stk.pop_back();
        }
    
        int j = stk.size() ? stk.back() + 1 : 0;
        dp[i] = (ans + sum[i] - sum[j] + stk.empty() + mod) % mod;
        sum[i + 1] = (sum[i] + dp[i] + mod) % mod;
        ans = (ans + dp[i] + mod) % mod;
        stk.push_back(i);

    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
