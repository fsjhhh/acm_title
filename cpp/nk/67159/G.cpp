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
 
#define int long long
 
void solve() {
    LL n, m, k;
    std::cin >> n >> m >> k;
    std::vector<PLL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].second;
    }
 
    std::sort(a.begin() + 1, a.end());
    
    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += a[i].first;
    }
    if (sum > m) {
        std::cout << "-1\n";
        return ;
    }

    auto check = [&](int x) -> bool {
        LL t = k / 2;
        std::priority_queue<int, std::vector<int>, std::greater<int>> q1, q2;
        for (int i = 1; i <= n; i++) {
            if (a[i].second < x) {
                q1.push(a[i].first);
            } else {
                q2.push(a[i].first);
            }
        }
        
        if (q2.size() < (k / 2 + 1)) {
            return false;
        }
        
        int w = 0;
        for (int i = 1; i <= (k / 2); i++) {
            w += q1.top();
            q1.pop();
            w += q2.top();
            q2.pop();
        }
        w += q2.top();
 
        if (w <= m) {
            return true;
        } else {
            return false;
        }
 
    };
 
    int l = 1, r = 1e9 + 10;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
 
    std::cout << l << "\n";
     
     
 
}
 
signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
