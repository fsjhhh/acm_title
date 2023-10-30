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

const int N = 1010, mod = 1e9 + 7;
LL d[N], s[N];
LL st[N];

void solve()
{
	int t, a, b;
	cin >> t >> a >> b;
	
	LL res = 1;
	st[1] = 1;
	for (int i = 1; i <= t; i ++ )
	{
		if (st[i])
		{
			for (int j = i + a; j <= min(t, i + b - 1); j ++ )
			{
				res = (res + st[i]) % mod;
				st[j] = (st[j] + st[i]) % mod;
			}
			if (i + b <= t)
				res = ((res - st[i]) % mod + mod) % mod;
		}

	}

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
