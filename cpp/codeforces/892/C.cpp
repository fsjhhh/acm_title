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

LL ans; 
LL a[500], b[500];
bool st[500];
LL s, z;

void dfs(int u, int x) {
    if (u == x + 1) {
        LL sum = 0, maxx = 0;
        for (int i = 1; i <= x; i ++ ) {
            sum += a[i] * i;
            maxx = std::max(maxx, a[i] * i);
        }
        if (ans < sum - maxx) {
            s = sum;
            z = maxx;
            for (int i = 1; i <= x; i ++ ) {
                b[i] = a[i];
            }
        }
        ans = std::max(ans, sum - maxx);
        return ;
    }
    for (int i = 1; i <= x; i ++ ) {
        if (!st[i]) {
            st[i] = true;
            a[u] = i;
            dfs(u + 1, x);
            st[i] = false;
        }
    }
}

void calc(int x) {
    ans = 0;
    memset(st, 0, sizeof st);
    dfs(1, x);
    for (int i = 1; i <= x; i ++ ) {
        std::cout << b[i] << " \n"[i == x];
    }
    std::cout << x << " " << s << " " << z << " " << ans << "\n";
}

void solve()
{
    int n;
    std::cin >> n;
    LL sum = 0, zz = 0, ans = 0;
    for (LL i = 0; i < n; i ++ ) {
        sum += i * i;
        LL sum_x = sum;
        zz = std::max(zz, i * i);
        LL zz_x = zz;
        LL t = n;
        for (LL j = i + 1; j <= n; j ++ ) {
            sum_x += j * t;
            zz_x = std::max(zz_x, j * t);
            t -- ;
        }
        ans = std::max(ans, sum_x - zz_x);
    }
    std::cout << ans << "\n";
    // for (int i = 2; i <= 10; i ++ ) {
    //     calc(i);
    // }
}

/*
2 3 4  5  6  7   8   9   10  11  12  13
2 7 17 35 62 100 152 219 303 406 530 678
*/
		
int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}