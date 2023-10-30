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

const int N = 1e5 + 10, M = 110;
int a[M][M][M];

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		int x1, y1, z1, x2, y2, z2;
		std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		for (int x = x1; x < x2; x ++ ) {
			for (int y = y1; y < y2; y ++ ) {
				for (int z = z1; z < z2; z ++ ) {
					a[x][y][z] = i;
				}
			}
		}
	}

	std::vector<std::set<int>> s(n + 1);
	for (int i = 0; i <=100; i ++ ) {
		for (int j = 0; j <= 100; j ++ ) {
			for (int k = 0; k <= 100; k ++ ) {
				int o = a[i][j][k];
				int x = a[i + 1][j][k], y = a[i][j + 1][k], z = a[i][j][k + 1];
				if (o != x && x && o) {
					s[o].insert(x);
					s[x].insert(o);
				}
				if (o != y && y && o) {
					s[o].insert(y);
					s[y].insert(o);
				}
				if (o != z && z && o) {
					s[o].insert(z);
					s[z].insert(o);
				}
			}
		}
	}
	for (int i = 1; i <= n; i ++ ) {
		std::cout << s[i].size() << "\n";
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