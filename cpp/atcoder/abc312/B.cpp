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

const int N = 110;
char a[N][N];

bool check(int x, int y) {
	for (int i = x; i <= x + 3; i ++ ) {
		for (int j = y; j <= y + 3; j ++ ) {
			if (i != x + 3 && j != y + 3) {
				if (a[i][j] != '#') {
					return false;
				}
			}
			else {
				if (a[i][j] != '.') {
					return false;
				}
			}
		}
	}
	for (int i = x + 5; i <= x + 8; i ++ ) {
		for (int j = y + 5; j <= y + 8; j ++ ) {
			if (i != x + 5 && j != y + 5) {
				if (a[i][j] != '#') {
					return false;
				}
			}
			else {
				if (a[i][j] != '.') {
					return false;
				}
			}
		}
	}
	return true;
}

void solve()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= m; j ++ ) {
			std::cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= m; j ++ ) {
			if (a[i][j] == '#') {
				if (check(i, j)) {
					std::cout << i << " " << j << "\n";
				}
			}
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