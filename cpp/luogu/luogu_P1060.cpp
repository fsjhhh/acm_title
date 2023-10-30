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

const int N = 50;
int v[N], w[N], n, m;
int f[30010];

void solve()
{
	std::cin >> n >> m;
	for (int i = 1; i <= m; i ++ )
	{
		int b;
		std::cin >> v[i] >> b;
		w[i] = v[i] * b;
	}

	for (int i = 1; i <= m; i ++ )
	{
		for (int j = n; j >= v[i]; j -- )
		{
			f[j] = std::max(f[j], f[j - v[i]] + w[i]);
		}
	}

	std::cout << f[n] << "\n";

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

