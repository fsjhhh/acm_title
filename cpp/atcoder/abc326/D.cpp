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
    std::string R, C;
    std::cin >> R >> C;
    std::vector<std::string> s(n);
    
    std::string S = "ABC";
    for (int i = 3; i < n; i++) {
        S += ".";
    }
    std::sort(S.begin(), S.end());
    std::vector<std::vector<char>> num(150);
    int cnt = 0;
    
    std::vector<char> x(n, '.');
    std::vector<bool> st(n, 0);
    auto dfs_1 = [&](auto self, int u) -> void {
        if (u == n) {
            num[cnt] = x;
            cnt ++ ;
            return ;
        }
        for (int i = 0; i < n; i++) {
            if (st[i]) {
                continue;
            }
            st[i] = true;
            x[u] = S[i];
            self(self, u + 1);
            st[i] = false;
        }
    };
    dfs_1(dfs_1, 0);
    bool pd = false;
    
    std::vector<std::vector<char>> z(n);
    std::vector<bool> flag(cnt, 0);
    std::vector<std::array<int, 3>> cc(n);
    std::vector<bool> col(n), row(n);
    auto dfs = [&](auto self, int u) -> void {
        if (u == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 3; j++) {
                    if (!cc[i][j]) {
                        return ;
                    }
                }
            }
            pd = true;
            std::cout << "Yes\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    std::cout << z[i][j];
                }
                std::cout << "\n";
            }
            return ;
        }
        for (int i = 0; i < cnt; i++) {
            if (flag[i]) {
                continue;
            }
            bool fl = false;
            
            for (int j = 0; j < n; j++) {
                if (num[i][j] == '.') {
                    continue;
                }
                if (cc[j][num[i][j] - 'A']) {
                    fl = true;
                    break;
                }
            }
            if (fl) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (!col[j] && num[i][j] != '.' && num[i][j] != C[j]) {
                    fl = true;
                    break;
                }
            }
            for (int j = 0; j < n; j++) {
                if (num[i][j] == '.') {
                    continue;
                } else {
                    if (num[i][j] != R[u]) {
                        fl = true;
                    }
                    break;
                }
            }
            if (fl) {
                continue;
            }
            std::vector<bool> cp(n);
            for (int j = 0; j < n; j++) {
                cp[j] = col[j];
            }
            for (int j = 0; j < n; j++) {
                if (!col[j] && num[i][j] != '.') {
                    col[j] = true;
                }
            }
            row[u] = true;
            for (int j = 0; j < n; j++) {
                if (num[i][j] == '.') {
                    continue;
                }
                cc[j][num[i][j] - 'A'] = 1;
            }
            z[u] = num[i];
            flag[i] = true;
            self(self, u + 1);
            if (pd) {
                return ;
            }
            row[u] = false;
            for (int j = 0; j < n; j++) {
                col[j] = cp[j];
            }
            for (int j = 0; j < n; j++) {
                if (num[i][j] == '.') {
                    continue;
                }
                cc[j][num[i][j] - 'A'] = 0;
            }
            flag[i] = false;
        }
    };

    dfs(dfs, 0);
    if (!pd) {
        std::cout << "No\n";
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
