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

const int N = 3e4 + 10;
int a[N];
bool st[N];

void solve()
{
	int w, n;
	std::cin >> w >> n;
	for (int i = 1; i <= n; i ++ )
		std::cin >> a[i];
	std::sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i ++ )
	{
		if (!st[i])
		{
			ans ++ ;
			for (int j = n; j > 0; j -- )
			{
				if (!st[j] && a[i] + a[j] <= w)
				{
					st[j] = true;
					break;
				}
			}
		}
	}

	std::cout << ans << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
