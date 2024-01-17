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

const int N = 1e5 + 10, M = 300;
LL pre[M][N], sum[M][N];

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 1; i < M; i++) {
        for (int j = 0; j < n; j++) {
            pre[i][i + j] = pre[i][j] + a[j];
            sum[i][i + j] = sum[i][j] + a[j] * (j / i + 1);
        }
    }

    while (q -- ) {
        int s, d, k;
        std::cin >> s >> d >> k;
        s -- ;
        int l = s, r = s + (d * k);
        if (d < M) {
            std::cout << sum[d][r] - sum[d][l] - (l / d) * (pre[d][r] - pre[d][l]) << " ";
        } else {
            LL ans = 0;
            for (int i = 0; i < k; i++) {
                ans += a[s + i * d] * (i + 1);
            }
            std::cout << ans << " ";
        }
    }
    std::cout << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
