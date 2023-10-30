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

const int N = 5e4 + 10;
int g[N], f[N], a[N];

void solve()
{
	int n;
	cin >> n;
	memset(g, -0x3f, sizeof g);
	memset(f, -0x3f, sizeof f);
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];
	int s = 0;
	for (int i = 1; i <= n; i ++ )
	{
		s = max(s, 0) + a[i];
		g[i] = max(g[i - 1], s);
	}
	s = 0;
	for (int i = n; i >= 1; i -- )
	{
		s = max(s, 0) + a[i];
		f[i] = max(f[i + 1], s);
	}

	int res = -INF;
	for (int i = 1; i <= n; i ++ )
		res = max(res, g[i] + f[i + 1]);

	cout << res << endl;
}

int main()
{
    IOS;
    int t = 1;
    cin >> t;
    while(t -- )
        solve();

    return 0;
}
