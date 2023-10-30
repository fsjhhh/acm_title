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

const int N = 3e4 + 10;
std::vector<LL> a[N];
std::vector<LL> b;

void solve()
{
    LL n, minn = INFL;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        int m;
        std::cin >> m;
        for (int j = 1; j <= m; j ++ ) {
            LL x;
            std::cin >> x;
            minn = std::min(minn, x);
            a[i].push_back(x);
        }
        std::sort(a[i].begin(), a[i].end());
        b.push_back(a[i][1]);
    }
    std::sort(b.begin(), b.end());
    // std::cout << minn << "\n";
    b[0] = minn;
    LL ans = 0;
    // std::cout << b[n - 1] << "\n";
    for (auto it : b) {
    //     std::cout << it << " ";
         ans += it;
    }
    // std::cout << "\n";
    std::cout << ans << "\n";
    for (int i = 1; i <= n; i ++ ) {
        a[i].clear();
    }
    b.clear();
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
