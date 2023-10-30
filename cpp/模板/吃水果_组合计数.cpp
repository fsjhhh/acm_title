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

const int N = 2010, mod = 998244353;
LL dp[N][N];

void solve()
{
	for (int i = 0; i <= 2000; i ++ )
	{
		for (int j = 0; j <= i; j ++ )
		{
			if (!j) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
		}
	}

	LL n, m, k;
	cin >> n >> m >> k;
	LL res = dp[n - 1][k] * m % mod;
	for (int i = 1; i <= k; i ++ ) res = res * (m - 1) % mod;

	cout << res << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
