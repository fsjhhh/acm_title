// Problem: 小富的idea
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/62880/F
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

const int N = 1e3 + 10;
const int M = 1e7 + 10;
int p[N];
int n;
PII b[N];
struct node {
	int x, y;
	int v;
}no[N];

struct dist {
	int time;
	int a, b;
}ti[M];
int idx;

bool cmp(dist a, dist b) {
	return a.time < b.time;
}

int calc(int a, int b) {
	int x1 = no[a].x, y1 = no[a].y, x2 = no[b].x, y2 = no[b].y;
	if (x1 == x2 && y1 == y2)
		return 0;
	if (!no[a].v && !no[b].v)
		return INF;
	int v = no[a].v + no[b].v;
	LL dist = (y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2);
	LL s = sqrt(dist);
	if (s * s < dist)
		s ++ ;
	LL tim = s / v;
	if (tim * v < s)
		tim ++ ;
	return tim;
}

int find(int u) {
	if (u != p[u])
		p[u] = find(p[u]);
	return p[u];
}

void solve()
{
	std::cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		p[i] = i;
	}
	for (int i = 1; i <= n; i ++ ) {
		std::cin >> no[i].x >> no[i].y >> no[i].v;
	}
	
	for (int i = 1; i <= n; i ++ ) {
		for (int j = i + 1; j <= n; j ++ ) {
			ti[++ idx] = {calc(i, j), i, j};		
		}
	}
	
	std::sort(ti + 1, ti + idx + 1, cmp);

	int q;
	std::cin >> q;
	for (int i = 1; i <= q; i ++ ) {
		int x;
		std::cin >> x;
		b[i] = {x, i};
	}
	std::sort(b + 1, b + q + 1);
	std::vector<int> ans(q + 1);
	int j = 1;
	for (int i = 1; i <= q; i ++ ) {
		while (j <= idx && ti[j].time <= b[i].first) {
			int x = ti[j].a, y = ti[j].b;
			int fx = find(x), fy = find(y);
			if (fx != fy) {
				p[fx] = fy;
				n -- ;
			}
			j ++ ;
		}
		ans[b[i].second] = n;
	}
	
	for (int i = 1; i <= q; i ++ ) {
		std::cout << ans[i] << "\n";
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