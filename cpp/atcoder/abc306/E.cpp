// Problem: E - Best Performances
// Contest: AtCoder - Toyota Programming Contest 2023#3（AtCoder Beginner Contest 306）
// URL: https://atcoder.jp/contests/abc306/tasks/abc306_e
// Memory Limit: 1024 MB
// Time Limit: 6000 ms

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
struct node {
	LL idx, val;
	bool operator<(const node it) const {
		if (val == it.val) {
			return idx < it.idx;
		}
		return val < it.val;
	}
};

std::multiset<node> stMax, stMin;
LL a[N];

void solve()
{
 	int n, k, q;
 	std::cin >> n >> k >> q;
 	for (int i = 1; i <= k; i ++ )
 		stMax.insert({i, 0});
 	for (int i = k + 1; i <= n; i ++ )
 		stMin.insert({i, 0});
 		
 	LL sum = 0;
 	while (q -- ) {
 		LL x, y;
 		std::cin >> x >> y;
 		if (k == n) {
 			sum += y - a[x];
 			a[x] = y;
 			std::cout << sum << "\n";
 			continue;
 		}
 		
 		if (stMax.find({x, a[x]}) != stMax.end()) {
 			stMax.erase(stMax.find({x, a[x]}));
 			stMax.insert({x, y});
 			sum += y - a[x];
 			a[x] = y;
 		}
 		else {
 			stMin.erase(stMin.find({x, a[x]}));
 			stMin.insert({x, y});
 			a[x] = y;
 		}
 		
 		if (stMax.begin() -> val < stMin.rbegin() -> val) {
 			auto nodeMax = *stMax.begin();
 			stMax.erase(stMax.find(nodeMax));
 			auto nodeMin = *stMin.rbegin();
 			stMin.erase(stMin.find(nodeMin));
 			stMax.insert(nodeMin);
 			stMin.insert(nodeMax);
 			sum += (nodeMin.val - nodeMax.val);
 		}
 		
 		std::cout << sum << "\n";
 		
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