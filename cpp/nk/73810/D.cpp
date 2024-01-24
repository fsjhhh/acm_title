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

const int N = 13;
LL dp[N][1 << N];
LL mp[N][N];

LL dfs(int x, int ma, int n) {
    if (x == n) {
        return 0;
    }

    if (dp[x][ma] != -1) {
        return dp[x][ma];
    }

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        if (!(ma & (1 << i))) {
            ans = std::max(ans, dfs(x + 1, ma | (1 << i), n) + mp[x][i]);
        }
    }

    return dp[x][ma] = ans;
}

void solve() {
    int n = 13;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> mp[i][j];
        }
    }

    memset(dp, -1, sizeof dp);

    LL ans = dfs(0, 0, n);

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
/*

*/

