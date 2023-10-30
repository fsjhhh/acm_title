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
#define IOS std::ios::sync_with_stdio(false); \
            std::cin.tie(0);              \
            std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 110;
int q[N], p[N];
int a[N];

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		q[i] = p[i] = 1;
		std::cin >> a[i];
	}
	for (int i = 2; i <= n; i ++ )
	{
		for (int j = 1; j < i; j ++ )
		{
			if (a[i] > a[j] && q[i] <= q[j] + 1)
				q[i] = q[j] + 1;
		}
	}

	for (int i = n - 1; i >= 1; i -- )
	{
		for (int j = i + 1; j <= n; j ++ )
		{
			if (a[i] > a[j] && p[i] <= p[j] + 1)
				p[i] = p[j] + 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int len = p[i] + q[i] - 1;
		ans = std::max(len, ans);
	}
	std::cout << n - ans << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
