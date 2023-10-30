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

struct node {
	double v, r, cc, ram, pps, pri;
};

void solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	std::vector<node> yo(n + 1);
	for (int i = 1; i <= n; i ++ ) {
		scanf("%lf%lf%lf%lf%lf%lf", &yo[i].v, &yo[i].r, &yo[i].cc, &yo[i].ram, &yo[i].pps, &yo[i].pri);
	}  
	while (m -- ) {
		double cv, cr, ccc, cram, cpps;
		scanf("%lf%lf%lf%lf%lf", &cv, &cr, &ccc, &cram, &cpps);
		int ans = 0;
		double prii = 0;
		for (int i = 1; i <= n; i ++ ) {
			if (cv <= yo[i].v && cr <= yo[i].r && ccc <= yo[i].cc && cram <= yo[i].ram && cpps <= yo[i].pps) {
				if (ans == 0) {
					ans = i;
				}
				else {
					if (yo[ans].pri > yo[i].pri) {
						ans = i;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}

int main()
{
    IOS;
    int t = 1;
    scanf("%d", &t);
    while (t -- )
        solve();
    return 0;
}