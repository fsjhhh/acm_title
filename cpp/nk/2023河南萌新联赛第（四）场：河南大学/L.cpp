// Problem: 7是大奖？
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/62880/L
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

LL a[22], idx;

LL f[20][20][20], g[20][1 << 7][2];

LL dfs(LL pos, int num, bool lim, LL cnt) {
	if (!pos)
		return cnt;
	if (f[pos][cnt][num] != -1 && !lim)
		return f[pos][cnt][num];
	int ca = (lim ? a[pos] : 9);
	LL ans = 0;
	for (int i = 0; i <= ca; i ++ ) {
		ans += dfs(pos - 1, num, (lim && i == ca), cnt + (i == num));
	}
	
	if (!lim) {
		f[pos][cnt][num] = ans;
	}
	
	return ans;
	
}

LL dfs1(LL pos, int num, bool lim, bool hav) {
	if (!pos)
		return hav;
	if (g[pos][num][hav] != -1 && !lim)
		return g[pos][num][hav];
	int ca = (lim ? a[pos] : 9);
	LL ans = 0;
	for (int i = 0; i <= ca; i ++ ) {
		LL n_num = (i == 7 ? num + 1 : 0);
		ans += dfs1(pos - 1, n_num, (lim && i == ca), (hav || n_num == 7));
	}
	if (!lim)
		g[pos][num][hav] = ans;
	return ans;
}

LL calc(LL pos) {
	idx = 0;
	while (pos) {
		a[++ idx] = pos % 10;
		pos /= 10;
	}
	LL ans = 3 * dfs(idx, 7, true, 0) + dfs(idx, 5, true, 0);
	ans += (300 * dfs1(idx, 0, true, false));
	return ans;
}

void solve()
{
	memset(f, -1, sizeof f);
	memset(g, -1, sizeof g);
	
	LL l, r;
	std::cin >> l >> r;
	std::cout << calc(r) - calc(l - 1) << "\n";
    
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