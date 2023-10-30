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

const int N = 3010;
double p[N];
double f[N][N];

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) {
    	scanf("%lf", &p[i]);
    }

    f[0][0] = 1;
    for (int i = 1; i <= n; i ++ ) {
    	f[i][0] = f[i - 1][0] * (1 - p[i]);
    	for (int j = 1; j <= i; j ++ ) {
    		f[i][j] = f[i - 1][j - 1] * p[i] + f[i - 1][j] * (1 - p[i]);
    	}
    }
    
    double ans = 0;
    for (int i = 1; i <= n; i ++ ) {
    	if (i > n - i) {
    		ans += f[n][i];
    	}
    }
    printf("%0.12lf\n", ans);
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