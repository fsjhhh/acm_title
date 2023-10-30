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

const int N = 210;
int a[N][N], f[N];

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i < n; i ++ )
	{
		for (int j = i + 1; j <= n; j ++ )
			std::cin >> a[i][j];
		f[i] = INF;
	}
	for (int i = n - 1; i >= 1; i -- )
		for (int j = i + 1; j <= n; j ++ )
			f[i] = std::min(f[i], f[j] + a[i][j]);
	std::cout << f[1] << "\n";
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

