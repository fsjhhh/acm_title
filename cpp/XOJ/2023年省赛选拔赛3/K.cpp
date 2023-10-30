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
LL a[N], b[N], sum[N];

void solve()
{
 	int n;
 	std::cin >> n;
 	for (int i = 1; i <= n; i ++ ) {
 		std::cin >> a[i];
 	}
 	for (int i = 1; i < n; i ++ ) {
 		b[i] = a[i] - a[i + 1];	
 	}

 	std::sort(b + 1, b + n);
 	for (int i = 1; i < n; i ++ ) {
 		sum[i] = sum[i - 1] + b[i];
 	}
 	int q;
 	std::cin >> q;
 	while (q -- ) {
 		int op, x;
 		std::cin >> op >> x;
 		if (op == 1) {
 			std::cout << sum[n - x] << "\n";
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