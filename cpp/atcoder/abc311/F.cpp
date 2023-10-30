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

const int N = 2010, mod = 998244353;
char mp[N][N];
LL f[N][N];

void solve()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			std::cin >> mp[i][j];

	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= m; j ++ ) {
			if (mp[i][j] == '#') {
				mp[i + 1][j] = '#';
				mp[i + 1][j + 1] = '#';
			}
		}
	}

	f[0][n + 1] = 1;
	
	for (int i = 1; i <= m; i ++ ) {
		LL sum = 0;
		for (int j = n + 1; j >= 1; j -- ) {
			sum = (sum + f[i - 1][j]) % mod;
			if (j > 0 && mp[j - 1][i] == '#') {
				continue ;
			}
			if (j > 0) {
				f[i][j] = (sum + f[i - 1][j - 1]) % mod;
			}
			else {
				f[i][j] = sum;
			}
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n + 1; i ++ ) {
		ans = (ans + f[m][i]) % mod;
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