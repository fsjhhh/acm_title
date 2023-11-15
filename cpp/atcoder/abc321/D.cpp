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
    LL n, m, p;
    std::cin >> n >> m >> p;
    std::vector<LL> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    std::vector<LL> sum(m);

    sum[0] = b[0];
    for (int i = 1; i < m; i++) {
        sum[i] = sum[i - 1] + b[i];
    }

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < p) {
            int l = 0, r = m - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                bool pd = false;
                if (b[mid] + a[i] <= p) {
                    pd = true;
                }
                if (pd) {
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }
            if (l == 0) {
                if (a[i] + b[l] > p) {
                    ans += (p * m);
                    continue;
                }
            }
            ans += (sum[l] + a[i] * (l + 1) + p * (m - l - 1));
        }
        else {
            ans += ((n - i) * m * p);
            break;
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

