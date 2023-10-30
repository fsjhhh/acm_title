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
PII v[N], b[N];
int idx;

void solve()
{
    int n;
    idx = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        int l, r, a, b;
        std::cin >> l >> r >> a >> b;
        v[i] = {l, b};
    }

    std::sort(v + 1, v + n + 1);

    for (int i = 1; i <= n; i ++ ) {
        if (idx != 0 && v[i].first <= b[idx].second) {
            b[idx].second = std::max(v[i].second, b[idx].second);
        }
        else {
            b[++ idx ] = v[i];
        }
    }
    b[++ idx ] = {INF, 0};
    int q;
    std::cin >> q;
    while (q -- ) {
        int x;
        std::cin >> x;
        int l = 1, r = idx;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (b[mid].first >= x + 1) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        std::cout << std::max(b[l - 1].second, x) << " ";
    }
    std::cout << "\n";

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