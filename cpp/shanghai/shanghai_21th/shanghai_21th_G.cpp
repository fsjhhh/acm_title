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
#define IOS ios::sync_with_stdio(false); \
            cin.tie(0);              \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 2010, M = 1e9;
LL a[N][N];
LL s[N][N];

bool check(int x1, int y1, int x2, int y2)
{
	LL ans = (s[x1][y1] - s[x2 - 1][y1] - s[x1][y2 - 1] + s[x2 - 1][y2 - 1]);
	//printf("%lld\n", ans);
	if (ans < 0)
		return true;
	else
		return false;
}

void solve()
{
	LL n, m, d_x, d_y;
	scanf("%lld%lld%lld%lld", &n, &m, &d_x, &d_y);
	memset(s, 0, sizeof s);
	memset(a, 0, sizeof a);
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			scanf("%lld", &a[i][j]);
	/*for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= m; j ++ )
		{
			printf("%lld ", a[i][j]);
		}
		puts("");
	}*/
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			s[i][j] = (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j]);
	/*for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= m; j ++ )
		{
			printf("%lld ", s[i][j]);
		}
		puts(" ");
	}*/
	bool pd = true;
	if (s[n][m] <= 0)
	{
		pd = false;
	}
	for (int i = d_x; i <= n; i ++ )
		for (int j = d_y; j <= m; j ++ )
			if (!check(i, j, i - d_x + 1, j - d_y + 1))
			{
				printf("NO\n");
				return ;
			}
	if (pd)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
    IOS;
    LL t = 1;
    scanf("%d", &t);
    while(t -- )
        solve();

    return 0;
}
