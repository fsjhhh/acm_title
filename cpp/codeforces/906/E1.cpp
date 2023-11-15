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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<PII> seg(m);
    std::vector<int> sum(n + 2);
    for (int i = 0; i < m; i++) {
        int L, R;
        std::cin >> L >> R;
        seg[i] = {L, R};
        sum[L] ++ , sum[R + 1] -- ;
    }
    
    std:sort(seg.begin(), seg.end());
    
    for (int i = 1; i <= n; i++) {
        sum[i] += sum[i - 1];
    }
    
    int cnt_0 = 0;
    for (int i = 1; i <= n; i++) {
        cnt_0 += (sum[i] == 0);
    }
    
    std::vector<int> f1(n + 2);
    for (int i = 1; i <= n; i++) {
        f1[i] = (sum[i] == 1);
    }
    for (int i = 1; i <= n; i++) {
        f1[i] += f1[i - 1];
    }
    
    std::vector<int> f2(n + 2);
    for (int i = 1; i <= n; i++) {
        f2[i] = (sum[i] == 2);
    }
    for (int i = 1; i <= n; i++) {
        f2[i] += f2[i - 1];
    }
    
    int ans = cnt_0;
    std::vector<int> maxx(m);
    for (int i = 0; i < m; i++) {
        auto [L, R] = seg[i];
        maxx[i] = f1[R] - f1[L - 1];
    }
    std::sort(maxx.begin(), maxx.end());
    ans = std::max(ans, cnt_0 + maxx[m - 1] + maxx[m - 2]);
    
    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> q;
    std::vector<PII> g(n + 1);
    int idx = 0;
    
    for (int i = 1; i <= n; i++) {
        while (q.size()) {
            auto [r, j] = q.top();
            if (r < i) {
                q.pop();
            } else {
                break;
            }
        }
        
        while (idx < m) {
            auto [L, R] = seg[idx];
            if (L > i) {
                break;
            }
            q.push({R, idx});
            idx ++ ;
        }
        
        if (sum[i] != 2) {
            continue;
        } else {
            auto [r1, j1] = q.top();
            q.pop();
            auto [r2, j2] = q.top();
            g[i] = {j1, j2};
            q.push({r1, j1});
        }
        
    }
    // std::cerr << ans << "\n";
    for (int i = 1; i <= n; i++) {
        if (sum[i] != 2) {
            continue;
        }
        auto [a, b] = g[i];
        if (a > b) {
            std::swap(a, b);
        }
        auto [L1, R1] = seg[a];
        auto [L2, R2] = seg[b];
        int cnt_2 = f2[std::min(R1, R2)] - f2[L2 - 1];
        int cnt_1 = f1[R1] - f1[L1 - 1] + f1[R2] - f1[L2 - 1];
        // std::cerr << cnt_1 << " " << cnt_2 << "\n";
        ans = std::max(ans, cnt_0 + cnt_1 + cnt_2);
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
