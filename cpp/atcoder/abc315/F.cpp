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
#include <iomanip> // std::fixed() std::setprecision(x) 保留x位小数
#include <array>
//#include <bits/stdc++.h>
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

constexpr int K = 30;
constexpr double inf = 1E9;

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        std::cin >> x[i] >> y[i];
    }

    std::vector f(n + 1, std::vector<double>(K, inf));
    double ans = inf;
    f[1][0] = 0;
    for (int i = 1; i < n; i ++ ) {
        for (int j = 0; j < K; j ++ ) {
            for (int k = i + 1; k <= n && j + k - i - 1 < K; k ++ ) {
                int nj = j + k - i - 1;
                f[k][nj] = std::min(f[k][nj], f[i][j] + std::sqrt((x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k])));
            }
        }
    }

    for (int i = 0; i < K; i ++ ) {
        ans = std::min(ans, f[n][i] + (i == 0 ? 0 : (1 << (i - 1))));
    }
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";
}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}