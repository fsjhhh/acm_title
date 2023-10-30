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
    std::string s;
    std::cin >> s;
    int n = s.size();
    s = " " + s;
    LL ans = INFL;
    for (char c = 'a'; c <= 'z'; c ++ ) {
        LL sum = 0;
        for (int i = 1; i <= n; i ++ ) {
            LL tmp = abs((int)c - (int)s[i]);
            tmp = std::min(tmp, 26 - tmp);
            sum += tmp;
        }
        ans = std::min(sum, ans);
    }
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