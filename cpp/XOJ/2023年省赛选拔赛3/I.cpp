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

const int N = 5e5 + 10;
int a[N];

void solve()
{
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i < n; i ++ ) {
    	int x, y, z;
    	std::cin >> x >> y >> z;
    	a[x] ^= z;
    	a[y] ^= z;
    }

    while (q -- ) {
    	int op;
    	std::cin >> op;
    	if (op == 1) {
    		int x, y, z;
    		std::cin >> x >> y >> z;
    		a[x] ^= z;
    		a[y] ^= z;
    	}
    	if (op == 2) {
    		int x;
    		std::cin >> x;
    		std::cout << a[x] << "\n";
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