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

const int N = 3e6 + 10;
int n, m;
int p[N], num[N];

int find(int u) {
	if (u != p[u]) {
		p[u] = find(p[u]);
	}
	return p[u];
}

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= 3 * n; i ++ ) {
    	p[i] = i;
    	num[i] = 1;
    }

    for (int i = 1; i <= m; i ++ ) {
    	int x, y;
    	std::cin >> x >> y;
    	int fx = find(x), fy = find(y);
    	if (fx != fy) {
    		p[fx] = fy;
    		num[fy] += num[fx];
    	}
    }


    LL ans = 0;
    LL _1 = 0, _2 = 0;
    for (int i = 1; i <= 3 * n; i ++ ) {
    	if (i == p[i]) {
    		LL t = num[i] % 3;
    		if (t == 1)
    			_1 ++ ;
    		if (t == 2)
    			_2 ++ ; 
    	}
    }
    if (_2 >= _1) {
    	LL t = _2 - _1;
    	ans += _1 * (1 + 1 + 2);
    	t = t / 3;
    	ans += (t * 2) * (1 + 1 + 2);
    }
    else {
    	LL t = _1 - _2;
    	ans += _2 * (1 + 1 + 2);
    	t = t / 3;
    	ans += t * (2 + 2 + 2);
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