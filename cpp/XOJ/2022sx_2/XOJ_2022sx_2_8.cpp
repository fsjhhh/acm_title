#include <iostream>
#include <stdio.h>
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

const int N = 510, mod = 998244353;
LL a[N][N], suml[N], sumr[N], sum[N][N];

void solve()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	LL res = 0;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
		{
			scanf("%lld", &a[i][j]);
			a[i][j] = a[i][j] % mod;
		}

	for (int i = 1; i <= k; i ++ )
	{
		char s[5];
		LL l, r;
		scanf("%s", s);
		scanf("%lld%lld", &l, &r);
		if (s[0] == 'r')
		{
			/*for (int i = 1; i <= m; i ++ )
			{
				res = (res + a[l][i] * ((r - sum[l][i]) % mod) % mod) % mod;
				sum[l][i] = r;
			}*/
			suml[l] = r;
		}
		else
		{
			/*for (int i = 1; i <= n; i ++ )
			{
				res = (res + a[i][l] * ((r - sum[i][l]) % mod) % mod) % mod;
				sum[i][l] = r;
			}*/
			sumr[l] = r;
		}
	}

	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			sum[i][j] = max(suml[i], sumr[j]);


	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
		{
			res = (res + a[i][j] * (sum[i][j] % mod)) % mod;
		}

	printf("%lld\n", res);

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
