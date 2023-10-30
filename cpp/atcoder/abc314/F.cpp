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

const int N = 4e5 + 10, mod = 998244353;
LL p[N], idx, siz[N];
LL f[N];
std::vector<PLL> edges[N];
LL n;

LL find(LL u) {
    if (u != p[u]) {
        p[u] = find(p[u]);
    }
    return p[u];
}

LL power(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

LL inv(LL x) {
    return power(x, mod - 2);
}

void dfs(int u, int P) {
    if (u <= n) {
        f[u] = P;
        return ;
    }
    for (auto [v, w] : edges[u]) {
        dfs(v, (w + P) % mod);
    }
}

void solve()
{
    std::cin >> n;
    for (int i = 1; i <= 2 * n; i ++ ) {
        p[i] = i;
        if (i <= n) {
            siz[i] = 1;
        }
    }
    idx = n;
    for (int i = 1; i < n; i ++ ) {
        LL u, v;
        std::cin >> u >> v;
        LL fp = find(u), fq = find(v);
        LL szp = siz[fp], szq = siz[fq];
        LL inv_ans = inv(szp + szq);
        if (fp != fq) {
            idx ++ ;
            edges[idx].push_back({fp, (szp * inv_ans) % mod});
            edges[idx].push_back({fq, (szq * inv_ans) % mod});
            p[fq] = idx;
            siz[idx] += siz[fq];
            p[fp] = idx;
            siz[idx] += siz[fp];
        }
    }

    dfs(idx, 0);

    for (int i = 1; i <= n; i ++ ) {
        std::cout << f[i] << " \n"[i == n];
    }

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