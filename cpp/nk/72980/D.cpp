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
    LL n, m;
    std::cin >> n >> m;
    std::vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<LL> b;
    LL z = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            b.push_back(z);
            z = 0;
        } else {
            z += a[i];
        }
    }

    std::queue<LL> q;
    z = m;
    LL ans = n - 1;
    for (int i = 0; i < (int)b.size(); i++) {
        if (z > b[i]) {
            z -= b[i];
            q.push(b[i]);
        } else {
            while (z <= b[i]) {
                if (q.size()) {
                    z += q.front();
                    ans += q.front();
                    q.pop();
                } else {
                    std::cout << "NO\n";
                    return ;
                }
            }
            z -= b[i];
            q.push(b[i]);
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
