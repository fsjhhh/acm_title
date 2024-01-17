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

#define int long long

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
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int mex = 0, sum = 0;
    std::vector<int> st(n + 1, 0);
    std::deque<PII> dq;
    for (int i = 0; i < n; i++) {
        st[a[i]] ++ ;
        while (st[mex]) {
            mex ++ ;
        }
        sum += mex;
        dq.push_back({mex, 1});
    }
    int ans = sum;
    for (int i = 0; i < n - 1; i++) {
        sum -= dq.front().first;
        dq.front().second -- ;
        if (!dq.front().second) {
            dq.pop_front();
        }
        PII tmp = {a[i], 0};
        while (dq.size() && dq.back().first >= a[i]) {
            tmp.second += dq.back().second;
            sum -= dq.back().first * dq.back().second;
            dq.pop_back();
        }

        sum += tmp.first * tmp.second;
        sum += n;
        dq.push_back(tmp);
        dq.push_back({n, 1});
        
        ans = std::max(ans, sum);

    }

    std::cout << ans << "\n";

}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
