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
int a[N], b[N], c[N];
int f[N][4];

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ )
		std::cin >> a[i] >> b[i] >> c[i];

	f[1][1] = a[1], f[1][2] = b[1], f[1][3] = c[1];
	for (int i = 2; i <= n; i ++ )
	{
		f[i][1] = std::max(f[i - 1][2] + a[i], f[i - 1][3] + a[i]);
		f[i][2] = std::max(f[i - 1][1] + b[i], f[i - 1][3] + b[i]);
		f[i][3] = std::max(f[i - 1][1] + c[i], f[i - 1][2] + c[i]);
	}

	int maxx = 0;
	for (int i = 1; i <= 3; i ++ )
		maxx = std::max(maxx, f[n][i]);
	std::cout << maxx << "\n";
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

