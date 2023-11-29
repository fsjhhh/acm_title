#include <future>
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
    int s[4], sum[4] = {0};
    std::cin >> s[0] >> s[1] >> s[2] >> s[3];
    std::vector<std::vector<int>> a(4);
    for (int i = 0; i < s[0]; i++) {
        int x;
        std::cin >> x;
        a[0].push_back(x);
        sum[0] += x;
    }
    for (int i = 0; i < s[1]; i++) {
        int x;
        std::cin >> x;
        a[1].push_back(x);
        sum[1] += x; 
    } 
    for (int i = 0; i < s[2]; i++) {
        int x;
        std::cin >> x;
        a[2].push_back(x);
        sum[2] += x;
    } 
    for (int i = 0; i < s[3]; i++) {
        int x;
        std::cin >> x;
        a[3].push_back(x);
        sum[3] += x;
    }

    int ans = 0;
    for (int x = 0; x < 4; x++) {
        std::vector<int> dp(2010);
        int su = sum[x];
        for (int i = 0; i < s[x]; i++) {
            for (int j = su / 2; j >= a[x][i]; j--) {
                dp[j] = std::max(dp[j], dp[j - a[x][i]] + a[x][i]);
            }
        }

        ans += (su - dp[su / 2]);

    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
