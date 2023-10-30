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

const int N = 1e5 + 10;
int e[N];

void solve()
{
    int n;
    std::cin >> n;
    LL ans = INFL;
    for (int i = 1; i <= n; i ++ ) {
    	int x;
    	std::cin >> x;
        e[i] = x;
    }
    int m;
    int t = ceil(sqrt((double)n));
    std::cin >> m;
    while (m -- ) {
    	int op;
    	std::cin >> op;
    	if (op == 0) {
    		int a, b;
    		std::cin >> a >> b;
    		e[a] = std::min(e[a], b);
    	}
    	else {
    		int a;
    		std::cin >> a;
            int i = 1;
            LL ans = e[a];
    		while (i <= t) {
                if (a - i >= 1) {
                    ans = std::min(ans, (LL)(a - (a - i)) * (a - (a - i)) + e[a - i]);
                }
                if (a + i <= n) {
                    ans = std::min(ans, (LL)(a - (a + i)) * (a - (a + i)) + e[a + i]);
                }
                i ++ ;
            }
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