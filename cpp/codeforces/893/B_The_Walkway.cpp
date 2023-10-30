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

void solve()
{
    int n, m, d;
    std::cin >> n >> m >> d;
    std::vector<int> s(m + 2);
    s[0] = -d + 1;
    s[m + 1] = n + 1;
    for (int i = 1; i <= m; i ++ ) {
        std::cin >> s[i];
    }
    LL sum = 0, cnt = 0;
    for (int i = 1; i <= m + 1; i ++ ) {
        sum += (s[i] - s[i - 1] - 1) / d;
    }
    LL ans = n + 1;
    for (int i = 1; i <= m; i ++ ) {
        LL res = sum;
        res -= (s[i] - s[i - 1] - 1) / d;
        res -= (s[i + 1] - s[i] - 1) / d;
        res += (s[i + 1] - s[i - 1] - 1) / d;
        res += m - 1;
        if (res < ans) {
            ans = res;
            cnt = 1;
        }
        else if (res == ans) {
            cnt ++ ;
        }
    }
    std::cout << ans << " " << cnt << "\n";
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