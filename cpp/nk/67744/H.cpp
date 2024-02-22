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
    std::map<int, int> mp_1, mp_2;
    std::vector zx(n, std::vector<int>(m)), fx(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        Fenwick<LL> bit_1(m), bit_2(m);
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '*') {
                if (i > 0 && j > 0) {
                    zx[i][j] = zx[i - 1][j - 1];
                }
                if (i > 0 && j < m - 1) {
                    fx[i][j] = fx[i - 1][j + 1];
                }
                zx[i][j] ++ ;
                fx[i][j] ++ ;
                cnt ++ ;
                int x = std::min(2 * zx[i][j] - 1, cnt);
                if (cnt >= 3 && zx[i][j] > 1) {
                    if (cnt % 2) {
                        ans += bit_1.rangeSum(j - x, j + 1);
                    } else {
                        ans += bit_2.rangeSum(j - x, j + 1);
                    }
                }
            } else {
                cnt = 0;
                for (auto [x, y] : mp_1) {
                    bit_1.add(x, - y);
                    mp_1[x] = 0;
                }
                for (auto [x, y] : mp_2) {
                    bit_2.add(x, -y);
                    mp_2[x] = 0;
                }
                continue;
            }
            if (cnt % 2) {
                int x = std::min(m - 1, j - 1 + 2 * fx[i][j] - 1);
                bit_1.add(j, 1);
                mp_1[x] ++ ;
            } else {
                int x = std::min(m - 1, j - 1 + 2 * fx[i][j] - 1);
                bit_2.add(j, 1);
                mp_2[x] ++ ;
            }
            if (mp_1[j]) {
                bit_1.add(j, -mp_1[j]);
                mp_1[j] = 0;
            }
            if (mp_2[j]) {
                bit_2.add(j, -mp_2[j]);
                mp_2[j] = 0;
            }
        }
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


