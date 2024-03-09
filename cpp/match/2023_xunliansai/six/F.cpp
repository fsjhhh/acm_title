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
    int n;
    std::cin >> n;
    std::vector mp(n + 1, std::vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> mp[i][j];
        }
    }

    std::vector<LL> col(n + 1), row(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            col[i] = col[i] + mp[i][j];
            row[j] = row[j] + mp[i][j];
        }
    }

    std::map<LL, std::vector<int>> c, r;
    for (int i = 1; i <= n; i++) {
        c[col[i]].push_back(i);
        r[row[i]].push_back(i);
    }

    if (n <= 10) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                for (int c = 1; c <= n; c++) {
                    for (int d = 1; d <= n; d++) {
                        if (a == c && b == d) {
                            continue;
                        }
                        std::swap(mp[a][b], mp[c][d]);
                        std::vector<LL> C(n + 1), R(n + 1);
                        for (int i = 1; i <= n; i++) {
                            for (int j = 1; j <= n; j++) {
                                C[i] = C[i] + mp[i][j];
                                R[j] = R[j] + mp[i][j];
                            }
                        }

                        bool ok = false;

                        for (int i = 2; i <= n; i++) {
                            if (C[i] != C[i - 1] || R[i] != R[i - 1]) {
                                ok = true;
                                break;
                            }
                        }

                        if (C[1] == R[1] && !ok) {
                            std::cout << a << " " << b << "\n";
                            std::cout << c << " " << d << "\n";
                            return ;
                        }
                        std::swap(mp[a][b], mp[c][d]);
                    }
                }
            }
        }
        return ;
    }

    auto calc = [&](LL sum, std::vector<int>& C, std::vector<int>& R) -> void {
        if (col[C[0]] - mp[C[0]][R[0]] + mp[C[1]][R[1]] == sum && 
            row[R[0]] - mp[C[0]][R[0]] + mp[C[1]][R[1]] == sum &&
            col[C[1]] - mp[C[1]][R[1]] + mp[C[0]][R[0]] == sum &&
            row[R[1]] - mp[C[1]][R[1]] + mp[C[0]][R[0]] == sum) {
            std::cout << C[0] << " " << R[0] << "\n";
            std::cout << C[1] << " " << R[1] << "\n";
        } else {
            std::cout << C[0] << " " << R[1] << "\n";
            std::cout << C[1] << " " << R[0] << "\n";
        } 
    };

    if (c.size() > 1 && r.size() > 1) {
        std::vector<int> C, R;

        LL sum;
        for (auto [x, it] : c) {
            if (it.size() <= 2) {
                for (auto y : it) {
                    C.push_back(y);
                }
            } else {
                sum = x;
            }
        }
        for (auto [x, it] : r) {
            if (it.size() <= 2) {
                for (auto y : it) {
                    R.push_back(y);
                }
            }
        }

        calc(sum, C, R);


    } else if (c.size() > 1) {
        std::vector<int> C;
        LL sum = row[1];
        for (auto [x, it] : c) {
            if (it.size() <= 2) {
                for (auto y : it) {
                    C.push_back(y);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (col[C[0]] - mp[C[0]][i] + mp[C[1]][i] == sum && col[C[1]] - mp[C[1]][i] + mp[C[0]][i] == sum) {
                std::cout << C[0] << " " << i << "\n";
                std::cout << C[1] << " " << i << "\n";
                return ;
            }
        }

    } else {
        std::vector<int> R;
        LL sum = col[1];
        for (auto [x, it] : r) {
            if (it.size() <= 2) {
                for (auto y : it) {
                    R.push_back(y);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (row[R[0]] - mp[i][R[0]] + mp[i][R[1]] == sum && row[R[1]] - mp[i][R[1]] + mp[i][R[0]] == sum) {
                std::cout << i << " " << R[0] << "\n";
                std::cout << i << " " << R[1] << "\n";
                return ;
            }
        }

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
