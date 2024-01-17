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
    std::string s;
    std::cin >> s;
    std::vector dp(26, std::vector(26, std::vector<LL>(n + 1)));
    
    std::vector C(n + 1, std::vector<LL>(n + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j) {
                C[i][j] = 1;
                continue;
            }
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 2; k <= j - i + 1; k++) {
                (dp[s[i] - 'a'][s[j] - 'a'][k] += C[j - i - 1][k - 2]) %= mod;
            }
        }
    }

    int q;
    std::cin >> q;
    while (q -- ) {
        char x, y;
        int k;
        std::cin >> x >> y >> k;
        std::cout << dp[x - 'a'][y - 'a'][k] << "\n";
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
