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

std::vector<int> d[5];

int a[5];
bool st[5];
LL ans = 0;

void dfs(int u) {
    if (u > 4) {
        LL sum = 0;
        for (int i = 1; i <= 4; i ++ ) {    
            for (int j = d[a[i]].size() - 1; j >= 0; j -- ) {
                sum = sum * 2 + d[a[i]][j];
            }
        }
        ans = std::max(ans, sum);
        return ;
    }
    for (int i = 1; i <= 4; i ++ ) {
        if (!st[i]) {
            a[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}

void solve()
{
    LL n;
    std::cin >> n;
    std::vector<int> s(33);
    for (int i = 1; i < 33; i ++ ) {
        s[i] = n % 2;
        n /= 2;
    }
    
    for (int i = 1; i <= 32; i ++ ) {
        if (i >= 1 && i <= 8) {
            d[1].push_back(s[i]);
        }
        if (i >= 9 && i <= 16) {
            d[2].push_back(s[i]);
        }
        if (i >= 17 && i <= 24) {
            d[3].push_back(s[i]);
        }
        if (i >= 25 && i <= 32) {
            d[4].push_back(s[i]);
        }
    }

    dfs(1);

    std::cout << ans << "\n";

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