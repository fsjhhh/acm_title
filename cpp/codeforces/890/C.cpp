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

const int N = 1010, M = 1e9;
LL a[N];
LL n, k;
LL ans;

bool check(LL x) {
    LL m = k, res = x;
    for (int i = 1; i <= n; i ++ ) {
        m = k;
        res = x;
        for (int j = i; j <= n; j ++ ) {
            if (res > a[j]) {
                if (j == n) {
                    m = -1;
                }
                m -= (res - a[j]);
                res -- ;
            }
            else {
                break;
            }
        }
        if (m >= 0) {
            return true;
        }
    }
    return false;
}

void solve()
{

	std::cin >> n >> k;
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
    }
    LL l = 1, r = M;
    ans = a[n];
    while (l < r) {
        LL mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
            ans = std::max(ans, mid);
        }
        else {
            r = mid - 1;
        }
    }
    std::cout << ans << "\n";
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