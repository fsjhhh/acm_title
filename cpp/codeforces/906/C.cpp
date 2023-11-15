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
    std::string s;
    std::cin >> s;

    int num_0 = 0, num_1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            num_0 ++ ;
        } else {
            num_1 ++ ;
        }
    }

    if (n % 2 || num_0 != num_1) {
        std::cout << "-1\n";
        return ;
    }
    
    s = ' ' + s;
    int q = 0, cnt_q = 0, h = 0, cnt_h = 0;
    std::vector<int> ans;
    for (int i = 1, j = n; i < j; ) {
        if (s[i] == s[j]) {
            if (ans.size() > 300) {
                std::cout << "-1\n";
                return ;
            }
            if (s[i] == '1') {
                ans.push_back(i - 1 + 2 * (cnt_q - q) + q);
                q ++ ;
                cnt_q ++ ;
                if (h == 0) {
                    j -- ;
                } else {
                    h -- ;
                }
            } else {
                ans.push_back(j + 2 * cnt_q + h);
                h ++ ;
                cnt_h ++ ;
                if (q == 0) {
                    i ++ ;
                } else {
                    q -- ;
                }
            }
        } else {
            if (q == 0) {
                i ++ ;
            } else {
                q -- ;
            }
            if (h == 0) {
                j -- ;
            } else {
                h -- ;
            }
        }
    }
    std::cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
