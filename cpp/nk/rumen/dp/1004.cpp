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

void solve()
{
	int n, ans = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= i; j ++ )
		{
			int x = ans, w = 0;
			while (x)
			{
				w ++ ;
				x /= 10;
			}
			x = 4 - w;
			for (int i = 1; i <= x; i ++ )
				printf(" ");
			printf("%d", ans ++ );
		}
		printf("\n");
	}
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}
