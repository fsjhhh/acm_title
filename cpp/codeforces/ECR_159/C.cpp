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
    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    std::vector<LL> c;
    for (int i = 1; i < n; i++) {
        c.push_back(a[i] - a[i - 1]);
    }

    if (n == 1) {
        std::cout << 1 << "\n";
        return ;
    }

    // std::sort(c.begin(), c.end());
    LL g = c[0];
    for (int i = 1; i < (int)c.size(); i++) {
        g = std::__gcd(g, c[i]);
    }
    
    LL ans = 0, num = 1;
    bool pd = false;
    for (int i = 0; i < (int)c.size(); i++) {
        LL w = c[i] / g;
        if (w > 1) {
            pd = true;
        }
        ans = ans + (c[i] / g) * num;
        num ++ ;
    }

    if (!pd) {
        ans += n;
    } else {
        LL x = 0, y = 0;
        for (int i = (int)c.size() - 1; i >= 0; i--) {
            if (c[i] / g > 1) {
                x = y + 1;
                break;
            }
            y += c[i] / g;
        }
        ans += x;
    }
    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
