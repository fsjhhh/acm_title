// Problem: C. Digital Logarithm
// Contest: Codeforces - Educational Codeforces Round 135 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1728/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
const int INF = 1e9;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5 + 10;
int a[N], b[N];

int get(int x) {
	int res = 0;
	while (x) {
		x /= 10;
		res ++ ;
	}
	return res;
}

void solve()
{
 	int n;
 	std::cin >> n;
	std::priority_queue<int> qa, qb;
	for (int i = 1; i <= n; i ++ ) {
		int x;
		std::cin >> x;
		qa.push(x);
	}
	for (int i = 1; i <= n; i ++ ) {
		int x;
		std::cin >> x;
		qb.push(x);
	}
	int ans = 0;
	while (qa.size() && qb.size()) {
		int ta = qa.top(), tb = qb.top();
		qa.pop();
		qb.pop();
		if (ta != tb) {
			if (ta > tb) {
				qa.push(get(ta));
				qb.push(tb);
			}
			else {
				qa.push(ta);
				qb.push(get(tb));
			}
			ans ++ ;
		}
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