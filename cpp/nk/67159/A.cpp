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
    std::vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    std::sort(a.begin(), a.end());
    int t = sum % 3;
    if (t == 0) {
        if (sum == 0) {
            std::cout << "0\n";
            return ;
        } else {
            for (int i = n - 1; i >= 0; i--) {
                std::cout << a[i];
            }
            std::cout << "\n";
        }
    } else if (t == 1) {
        int tmp = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] % 3 == 1) {
                tmp = i;
                break;
            }
        }
        if (tmp == -1) {
            int z[2] = {-1, -1}, temp = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] % 3 == 2) {
                    z[temp] = i;
                    temp ++ ;
                    if (temp == 2) {
                        break;
                    }
                }
            }
            if (temp < 2) {
                std::cout << "-1\n";
            }
            sum -= (a[z[0]] + a[z[1]]);
            if (sum == 0) {
                if (n == 2) {
                    std::cout << "-1\n";
                    return ;
                }
                std::cout << "0\n";
                return ;
            }
            for (int i = n - 1; i >= 0; i--) {
                if (i != z[0] && i != z[1]) {
                    std::cout << a[i];
                }
            }
            std::cout << "\n";
        } else {
            sum -= a[tmp];
            if (sum == 0) {
                if (n == 1) {
                    std::cout << "-1\n";
                    return ;
                }
                std::cout << "0\n";
                return ;
            }
            for (int i = n - 1; i >= 0; i--) {
                if (i != tmp) {
                    std::cout << a[i];
                }
            }
            std::cout << "\n";
        }
    } else {
        int tmp = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] % 3 == 2) {
                tmp = i;
                break;
            }
        }
        if (tmp == -1) {
            int z[2] = {-1, -1}, temp = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] % 3 == 1) {
                    z[temp] = i;
                    temp ++ ;
                    if (temp == 2) {
                        break;
                    }
                }
            }
            if (temp < 2) {
                std::cout << "-1\n";
            }
            sum -= (a[z[0]] + a[z[1]]);
            if (sum == 0) {
                if (n == 2) {
                    std::cout << "-1\n";
                    return;
                }
                std::cout << "0\n";
                return ;
            }
            for (int i = n - 1; i >= 0; i--) {
                if (i != z[0] && i != z[1]) {
                    std::cout << a[i];
                }
            }
            std::cout << "\n";
        } else {
            sum -= a[tmp];
            if (sum == 0) {
                if (n == 1) {
                    std::cout << "-1\n";
                    return ;
                }
                std::cout << "0\n";
                return ;
            }
            for (int i = n - 1; i >= 0; i--) {
                if (i != tmp) {
                    std::cout << a[i];
                }
            }
            std::cout << "\n";
        }
    }

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
