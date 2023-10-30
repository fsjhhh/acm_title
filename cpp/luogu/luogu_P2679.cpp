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
const int mod = 1000000007;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string a, b;
    std::cin >> a >> b;

    std::vector f(n + 1, std::vector<int>(n + 1)), sum(n + 1, std::vector<int>(n + 1));

    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ ) {
    	for (int j = m; j >= 1; j -- ) {
    		for (int t = k; t >= 1; t -- ) {
    			f[j][t] = (f[j][t] + (sum[j][t] = (a[i - 1] == b[j - 1] ? sum[j - 1][t] + f[j - 1][t - 1] % mod : 0))) % mod;
    		}
    	}
    }

    std::cout << f[m][k] << "\n";

} 

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}