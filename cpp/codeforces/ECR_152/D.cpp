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

const int N = 2e5 + 10;
int a[N];
bool st[N];

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        std::cin >> a[i];
    }
    LL ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i] == 0)
            continue;
        int j = i;
        bool pd = false;
        while (j <= n && a[j] != 0) {
            if (a[j] == 2)
                pd = true;
            j ++ ;
        }

        if (pd) {
            st[i - 1] = st[j] = true;
        }
        else {
            if (i - 1 >= 1 && !st[i - 1])
                st[i - 1] = true;
            else
                st[j] = true;
        }
        ans ++ ;
        i = j - 1;
    }

    for (int i = 1; i <= n; i ++ ) {
        if (a[i] == 0 && !st[i]) {
            ans ++ ;
        }
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