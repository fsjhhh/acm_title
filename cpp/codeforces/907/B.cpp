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
    int n, q;
    std::cin >> n >> q;
    std::vector<LL> a(n);
    std::vector<LL> v(n); 
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        for (int j = 0; j <= 30; j++) {
            if (a[i] >> j & 1) {
                v[i] = j;
                break;
            }
        }
    }
    std::vector<int> x(q);
    for (int i = 0; i < q; i++) {
        std::cin >> x[i];
    }
    
    std::vector<LL> z(31);
    for (int i = 0; i <= 30; i++) {
        int t = i;
        for (int j = 0; j < q; j++) {
            if (t >= x[j]) {
                z[i] += (1ll << (x[j] - 1));
                t = x[j] - 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] + z[v[i]] << " \n"[i == n - 1];
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
