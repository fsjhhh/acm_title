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

#define int long long

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
 
    Fenwick(int n_ = 0) {
        init(n_);
    }
 
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
 
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
 
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
 
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> mp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mp[i];
    }

    LL ans = 0;
    std::vector zx(n, std::vector<int>(m, 0)), fx(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '*') {
                if (i > 0 && j > 0) {
                    fx[i][j] = fx[i - 1][j - 1];
                }
                if (i > 0 && j < m - 1) {
                    zx[i][j] = zx[i - 1][j + 1];
                }
                fx[i][j] ++ ;
                zx[i][j] ++ ;
            }
        }
    }
    
    Fenwick<int> sg(4 * m);
    std::vector<std::vector<int>> mp1(4 * m);
    auto calc = [&](int row, int l, int r) -> void {
        int mx = 0, i;
        for (i = l; i <= r; i += 2) {
            int L = i, R = i + 2 * zx[row][i] - 2;
            mp1[R].push_back(L);
            mx = std::max(mx, R);
            sg.add(i, 1);
            R = i;
            L = std::max(0ll, R - 2 * fx[row][i] + 2);
            ans += sg.rangeSum(L, i + 1);
            for (auto j : mp1[i]) {
                sg.add(j, -1);
            }
            mp1[i].clear();
        }
        for (; i <= mx; i += 2) {
            for (auto j : mp1[i]) {
                sg.add(j, -1);
            }
            mp1[i].clear();
        }
        
        mx = 0;
        for (i = l + 1; i <= r; i += 2) {
            int L = i, R = i + 2 * zx[row][i] - 2;
            mp1[R].push_back(L);
            mx = std::max(mx, R);
            sg.add(i, 1);
            R = i;
            L = std::max(0ll, R - 2 * fx[row][i] + 2);
            ans += sg.rangeSum(L, i + 1);
            for (auto j : mp1[i]) {
                sg.add(j, -1);
            }
            mp1[i].clear();
        }
        for (; i <= mx; i += 2) {
            for (auto j : mp1[i]) {
                sg.add(j, -1);
            }
            mp1[i].clear();
        }
        
    };
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '.') {
                continue;
            }
            int k = j;
            while (k < m && mp[i][k] == '*') {
                k ++ ;
            }
            calc(i, j, k - 1);
            j = k - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans -= (mp[i][j] == '*');
        }
    }

    std::cout << ans << "\n";
}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}


