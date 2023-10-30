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

const int N = 110;
double c[N];
std::vector<int> a[N];
double f[N];

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) {
        scanf("%lf", &c[i]);
        int p;
        scanf("%d", &p);
        int cnt = 0;
        for (int j = 1; j <= p; j ++ ) {
            int x;
            scanf("%d", &x);
            if (x) {
                a[i].push_back(x);
            }
            else {
                cnt ++ ;
            }
        }
        c[i] = (c[i] * 1.0 * p) / (p - cnt);
    }

    for (int i = m - 1; i >= 0; i -- ) {
        double ans = INFL;
        for (int j = 1; j <= n; j ++ ) {
            double tmp = 0;
            for (auto it : a[j]) {
                if (i + it < m) {
                    tmp += (f[i + it] + c[j]);
                }
                else {
                    tmp += c[j];
                }
            }
            tmp /= a[j].size();
            ans = std::min(ans, tmp);
        }
        f[i] = ans;
    }

    printf("%0.10lf\n", f[0]);

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