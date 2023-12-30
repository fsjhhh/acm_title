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

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), c(n);
    int z = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        z += (a[i] == 0);
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    int cnt = 0;
    int sum = 0;
    std::vector<int> res(n);
    int val = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            a[i] += c[i];
            c[i] = 0;
            res[i] = std::min(b[i], a[i]);
            val += res[i];
            sum += a[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!a[i] && val && b[i] != 0) {
            a[i] = 1 + c[i];
            c[i] = 0;
            res[i] = std::min(a[i], b[i]);
            val = val - 1 + res[i];
            cnt++;
            sum += a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        int t = 0;
        if (a[i] || val) {
            t = val - res[i] + a[i] + c[i];
        }
        std::cout << t << " \n"[i == n - 1];
    }
    
    std::vector<int> w;
    for (int i = 0; i < n; i++) {
        if (!b[i] && !a[i]) {
            w.push_back(c[i]);
        }
    }

    std::sort(w.begin(), w.end(), std::greater());

    for (int i = 0; i < (int)w.size(); i++) {
        if (val) {
            cnt ++ ;
            sum += w[i] + 1;
            val -- ;
        }
    }
    
    std::cout << sum - cnt << "\n";

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
