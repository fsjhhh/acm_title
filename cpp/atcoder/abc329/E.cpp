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
    int n, m;
    std::cin >> n >> m;
    std::string S, T;
    std::cin >> S >> T;
    std::queue<int> q;
    std::vector<bool> st(n);

    auto check = [&](int x) -> void {
        if (st[x]) {
            return ;
        }
        bool pd = true;
        for (int i = 0; i < m; i++) {
            pd &= ((S[x + i] == '#') || (S[x + i] == T[i]));
        }
        if (pd) {
            st[x] = true;
            q.push(x);
        }
    };

    for (int i = 0; i < (n - m + 1); i++) {
        check(i);
    }

    while (q.size()) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < m; i++) {
            S[t + i] = '#';
        }
        for (int i = std::max(t - m + 1, 0); i <= std::min(t + m - 1, n - m); i++) {
            check(i);
        }
    }

    std::string s;
    s.resize(n, '#');
    std::cout << (S == s ? "Yes\n" : "No\n");
}

void solve_dp() {
    int n, m;
    std::cin >> n >> m;
    std::string S, T;
    std::cin >> S >> T;
    std::vector dp(n + 1, std::vector<bool>(m + 1));

    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        if (i + m <= n) {
            for (int j = 0; j < m + 1; j++) {
                if (dp[i][j]) {
                    dp[i][0] = true;
                }
            }
        }
        if (dp[i][m]) {
            for (int j = 0; j < m + 1; j++) {
                dp[i][j] = true;
            }
        }
        for (int j = 0; j < m; j++) {
            if (dp[i][j] && S[i] == T[j]) {
                dp[i + 1][j + 1] = true;
            }
        }
    }
    std::cout << (dp[n][m] ? "Yes\n" : "No\n");

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve_dp();
    return 0;
}
