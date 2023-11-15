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
    std::vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> d[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d[i]; j++) {
            bool pd = false;
            int x = i;
            int t = i % 10;
            while (x)  {
                if (x % 10 != t) {
                    pd = true;
                }
                x /= 10;
            }
            int y = j;
            while (y) {
                if (y % 10 != t) {
                    pd = true;
                }
                y /= 10;
            }
            if (!pd) {
                ans ++ ;
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
