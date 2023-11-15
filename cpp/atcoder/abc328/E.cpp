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
const LL INFL = 1e18;

const int N = 30;

struct Edges {
    LL u, v, w;
}edges[2 * N];
int idx = 0;

LL res = INFL;
LL n, m, k;
bool st[N];
bool s[N];
int ans = 1;

void dfs(int u, LL an) {
    if (u == n - 1) {
        if (ans == n) {
            res = std::min(res, an);    
        }
        return ;
    }
    for (int i = 0; i < idx; i++) {
        if (!st[i]) {
            // std::cerr << i << "\n";
            LL x = edges[i].u, y = edges[i].v, w = edges[i].w;
            // std::cerr << x << " " << y << "\n";
            if (s[x] && !s[y]) {
                st[i] = true;
                s[y] = true;
                ans ++ ;
                // ans[u] = i;
                dfs(u + 1, (an + w) % k);
                s[y] = false;
                ans -- ;
                st[i] = false;
            } else if (s[y] && !s[x]) {
                st[i] = true;
                s[x] = true;
                ans ++ ;
                // ans[u] = i;
                dfs(u + 1, (an + w) % k);
                s[x] = false;
                ans -- ;
                st[i] = false;
            }
        }
    }

}

void solve() {
    // std::cin >> n >> m >> k;
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        LL u, v, w;
        // std::cin >> u >> v >> w;
        scanf("%lld%lld%lld", &u, &v, &w);
        edges[idx ++ ] = {u, v, w};
        // edges[idx ++ ] = {v, u, w};
    }

    s[1] = true;
    dfs(0, 0);
    // std::cout << res << "\n";
    printf("%lld\n", res);


}

int main() {
    // IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

