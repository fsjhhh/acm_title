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
#include <bitset>
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
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        std::cin >> a[i];
    }
    std::vector sum(n + 1, std::vector<int>(40));
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 0; j <= 30; j ++ ) {
            if ((a[i] >> j) & 1) {
                sum[i][j] ++ ;
            }
            sum[i][j] += sum[i - 1][j];
        }
    }

    int q;
    std::cin >> q;
    while (q -- ) {
        int ans = 0;
        int l, r;
        std::cin >> l >> r;
        for (int i = 30; i >= 0; i -- ) {
            int cnt_1 = sum[r][i] - sum[l - 1][i];
            int cnt_2 = r - l + 1 - cnt_1;
            if (cnt_1 < cnt_2) {
                ans = ans * 2 + 1;
            }
            else {
                ans *= 2;
            }
        }
        std::cout << ans << "\n";
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