#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
// #include <unordered_map>
#include <set>
// #include <unordered_set>
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

const int N = 1e5 + 10;
int a[N], b[N];
int f[N][25];
int n;

void pre() // dp
{
    memset(f, -1, sizeof f);
    int k=log((double)(n+1))/log(2.0);
    for (int i = 1; i <= n; i ++ )
        f[i][0] = b[i];
    for (int j = 1; j <= k; j ++ )
        for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
            f[i][j] = std::max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}

int rmq(int l, int r)
{
    if (l > r)
        return 0;
    int k=log((double)(r-l+1))/log(2.0);
    return std::max(f[l][k], f[r - (1 << k) + 1][k]);
}

void solve()
{
    while (1)
    {
        memset(b, 0, sizeof b);
        std::cin >> n;
        if (n == 0)
            break;
        int q;
        std::cin >> q;
        for (int i = 1; i <= n; i ++ )
        {
            std::cin >> a[i];
            if (i == 1)
                b[i] = 1;
            else
            {
                if (a[i] == a[i - 1])
                    b[i] = b[i - 1] + 1;
                else
                    b[i] = 1;
            }
        }
        pre();
        while (q -- )
        {
            int l, r;
            std::cin >> l >> r;
            int t = l;
            while (t <= r && a[t] == a[t - 1])
                t ++ ;
            int ans = rmq(t, r);
            ans = std::max(ans, t - l);
            std::cout << ans << "\n";
        }

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

