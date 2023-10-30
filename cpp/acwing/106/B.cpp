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
int a[N][N];

void solve()
{
	int n;
	std::cin >> n;

	memset(a, 0x3f, sizeof a);

	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			std::cin >> a[i][j];

	for (int k = 1; k <= n; k ++ )
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= n; j ++ )
				a[i][j] = std::min(a[i][j], a[i][k] + a[k][j]);

	int ma = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = i + 1; j <= n; j ++ )
			ma = std::max(ma, a[i][j]);

	std::cout << ma << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}
