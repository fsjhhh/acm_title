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
    std::string s;
    std::cin >> s;
    int n;
    std::cin >> n;
    int m = s.size();
    
    if (m < n) {
        std::cout << "-1\n";
        return ;
    }
    if (n == 0) {
        std::cout << s << "\n";
        return ;
    }

    std::string ans = s;
    bool pd = false;
    for (int i = m - n; i >= 0; i--) {
        if (s[i] == '1') { // 找到第一个1的位置
            ans[i] = '0'; // 反转
            n -- ;
            pd = true;
            for (int j = i + 1; j < m; j++) {
                ans[j] = '1'; // 全变成1
                if (s[j] == '0') {
                    n -- ;
                }
            }
            if (n > 0) {
                for (int j = m - 1; j > i; j--) {
                    if (s[j] == '1') { // 将原串是1变成0
                        ans[j] = '0';
                        n -- ;
                    }
                    if (n == 0) { // 符合条件，跳出
                        break;
                    }
                }
            }
            break;
        }
    }

    if (pd) {
        // 去掉前导零
        std::reverse(ans.begin(), ans.end());
        for (int i = m - 1; i >= 0; i--) {
            if (ans[i] == '0') {
                ans.pop_back();
            } else {
                break;
            }
        }
        std::reverse(ans.begin(), ans.end());
        std::cout << ans << "\n";
    } else {
        std::cout << "-1\n";
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
