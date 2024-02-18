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

#define int long long

const int mod = 1e9 + 7;

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int power(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

int inv(int x, int p) {
    return power(x, p - 2, p);
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        b[i] -- ;
    }

    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    std::vector<int> vis(n, -1), dp(n, -1), q(n);
    for (int i = 0; i < n; i++) {
        if (b[i] == i) {
            dp[i] = 0;
            continue;
        }
        int j = i;
        while (vis[j] == -1) {
            vis[j] = i;
            j = b[j];
        }

        if (vis[j] != i) {
            continue;
        }

        int k = j, len = 0;
        do {
            k = b[k];
            len ++ ;
        } while (k != j);

        auto dfs = [&](auto self, int u) -> void {
            if (u == k) {

                if (a[u] < a[b[u]]) {
                    dp[u] = 1;
                } else if (a[u] >= a[b[u]] + w[b[u]]) {
                    dp[u] = 0;
                }

                return ;
            }

            self(self, b[u]);

            if (dp[b[u]] == 0) {
                dp[u] = 0;
            } else if (dp[b[u]] == -1) {
                dp[u] = -1;
            } else {
                dp[u] = dp[b[u]] + 1;
            }

            if (a[u] < a[b[u]]) {
                dp[u] = 1;
            } else if (a[u] >= a[b[u]] + w[b[u]]) {
                dp[u] = 0;
            }
        };

        dfs(dfs, b[k]);

        int z = k;
        for (int w = 0; w < len; w++) {
            q[b[z]] = z;
            z = b[z];
        }

        if (dp[b[k]] == -1) {
            z = k;
            for (int w = 0; w < len; w++) {
                dp[z] = 0;
                z = b[z];
            }
        }

        if (dp[k] == -1) {
            z = k;
            for (int w = 0; w < len; w++) {
                if (dp[z] != -1) {
                    break;
                }
                if (dp[b[z]] == 0) {
                    dp[z] = 0;
                } else {
                    dp[z] = dp[b[z]] + 1;
                }
                z = q[z];
            }
        }

    }


    auto dfs = [&](auto self, int u) -> void {
        if (dp[u] != -1) {
            return ;
        }

        self(self, b[u]);

        if (dp[b[u]] == 0) {
            dp[u] = 0;
        } else {
            dp[u] = dp[b[u]] + 1;
        }

        if (a[u] < a[b[u]]) {
            dp[u] = 1;
        } else if (a[u] >= a[b[u]] + w[b[u]]) {
            dp[u] = 0;
        }

    };

    for (int i = 0; i < n; i++) {
        if (dp[i] == -1) {
            dfs(dfs, i);
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = std::max(mx, dp[i]);
    }

    std::vector<int> jc(mx + 1, 1);
    for (int i = 1; i <= mx; i++) {
        jc[i] = jc[i - 1] * i % mod;
    }

    for (int i = 0; i < n; i++) {
        if (dp[i] == 0) {
            std::cout << a[i] << " ";
        } else {
            int inve = inv(jc[dp[i]]);
            int wu = (a[i] + inve * w[i] % mod) % mod;
            std::cout << wu << " ";
        }
    }
    std::cout << "\n";

}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
