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
std::vector<LL> a[3];

void solve()
{
    LL n, m;
    std::cin >> n >> m;
    
    for (int i = 0; i < n; i ++ ) {
    	LL t, x;
    	std::cin >> t >> x;
    	a[t].push_back(x);
    }
    for (int i = 0; i < 3; i ++ ) {
    	std::sort(a[i].begin(), a[i].end(), std::greater<int>());
    }

    LL ans = 0, sum = 0;
    LL n1 = a[0].size(), n2 = a[1].size(), n3 = a[2].size();
    LL num1 = 0, num2 = 0;

    while (num1 < n1 && num1 < m) {
    	sum += a[0][num1 ++ ];
    }
    ans = sum;

    for (auto x : a[2]) {
    	m -- ;
    	if (num1 + num2 > m) {
    		if (num1 > 0 && (!num2 || a[0][num1 - 1] < a[1][num2 - 1])) {
    			sum -= a[0][-- num1];
    		}
    		else if (num2 > 0) {
    			sum -= a[1][-- num2];
    		}
    		else {
    			break;
    		}
    	}
    	while (num1 + num2 < m && num2 < n2 && x > 0) {
    		sum += a[1][num2 ++ ];
    		x -- ;
    	}

        while (num1 > 0 && num2 < n2 && a[0][num1 - 1] < a[1][num2] && x > 0) {
            sum -= a[0][-- num1];
            sum += a[1][num2 ++ ];
            x -- ;
        }

    	ans = std::max(ans, sum);
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