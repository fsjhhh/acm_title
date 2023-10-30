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
LL num[N];
std::map<LL, LL> s, ha;
std::map<LL, std::priority_queue<PLL, std::vector<PLL>, std::greater<PLL>>> c;
std::map<LL, LL> k[N];

std::queue<int> q;

void add(LL x, LL y) {
	LL &z = ha[x];
	z += y;
	std::priority_queue<PLL, std::vector<PLL>, std::greater<PLL>> &tp = c[x];
	while (tp.size()) {
		auto t = tp.top();
		tp.pop();
		if (t.first > z) {
			tp.push(t);
			break;
		}
		num[t.second] -- ;
		if (num[t.second] == 0) {
			q.push(t.second);
		}
	}
}

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ ) {
    	LL x, y;
    	std::cin >> x >> y;
    	s[x] += y;
    }
    int m;
    std::cin >> m;
    for (int i = 1; i <= m; i ++ ) {
    	int t;
    	std::cin >> num[i];
    	for (int j = 1; j <= num[i]; j ++ ) {
    		LL x, y;
    		std::cin >> x >> y;
    		c[x].push({y, i});
    	}
    	std::cin >> t;
    	for (int j = 1; j <= t; j ++ ) {
    		LL x, y;
    		std::cin >> x >> y;
    		k[i][x] = y;
    	}
    }
    LL ans = 0;
	for (int i = 1; i <= m; i ++ ) {
		if (!num[i]) {
			q.push({i});
		}
	}
	for (auto [x, y] : s) {
		add(x, y);
	}
	while (q.size()) {
		auto t = q.front();
		q.pop();
		ans ++ ;
		for (auto [x, y] : k[t]) {
			add(x, y);
		}
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