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
std::map<LL, std::vector<LL>> b;
LL a[N];

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
    	b[i - a[i]].push_back(a[i]);
    }
    LL ans = 0;
    for (auto &[z, it] : b) {
    	std::sort(it.begin(), it.end());
    	for (int i = it.size() - 1; i >= 0; i -= 2) {
    		LL sum = it[i] + it[i - 1];
            if (i == 0) {
                break;
            }
            // std::cout << sum << "\n";
    		if (sum > 0) {
    			 ans += sum;
                 // std::cout << sum << "\n";
    		}
    	}
        it.clear();
        // std::cout << ans << "\n";
    }
    std::cout << ans << "\n";
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