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

const int N = 1e5 + 10;

struct node {
	int x, y, z;
}a[N];

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i].x >> a[i].y >> a[i].z;
    }
    LL ans = 0;
    for (int i = 0; i <= 7; i ++ ) {
    	std::bitset<3> b(i);
    	std::vector<int> sum(n + 1, 0);
    	for (int j = 1; j <= n; j ++ ) {
    		if (b[0]) {
    			sum[j] += a[j].x;
    		}
    		else {
    			sum[j] -= a[j].x;
    		}
    		if (b[1]) {
    			sum[j] += a[j].y;
    		}
    		else {
    			sum[j] -= a[j].y;
    		}
    		if (b[2]) {
    			sum[j] += a[j].z;
    		}
    		else {
    			sum[j] -= a[j].z;
    		}
    	}
    	LL z = 0;
    	for (int j = 1; j <= n; j ++ ) {
    		if (sum[j] > 0) {
    			z += sum[j];
    		}
    	}
    	ans = std::max(z, ans);
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