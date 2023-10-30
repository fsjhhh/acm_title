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

const int N = 1e6 + 10;
int a[N], b[N];

void solve()
{
    int n;
    std::cin >> n;
    int n_1 = n * (n - 1) / 2;
    for (int i = 1; i <= n_1; i ++ ) {
    	std::cin >> a[i];
    }

    std::sort(a + 1, a + n_1 + 1);
    int idx = 0;
    for (int i = 1; i <= n_1; i += (n - idx)) {
    	b[++ idx ] = a[i];
    }
    b[n] = b[n - 1];
    for (int i = 1; i <= n; i ++ ) {
    	std::cout << b[i] << " \n"[i == n];
    }

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