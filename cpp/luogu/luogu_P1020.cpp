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
            cin.tie(0);                  \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10;
int a[N], f[N], g[N];

void solve()
{
	/*int n = 0;
	int x;
	while (cin >> x)
	{
		a[++ n ] = x;
	}*/

	int n = 8;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];

	int idx = 0;
	f[0] = INF;
	for (int i = 1; i <= n; i ++ )
	{
		if (a[i] <= f[idx])
			f[++ idx ] = a[i];
		else
		{
			int l = 0, r = idx;
			while (l < r)
			{
				int mid = (l + r) >> 1;
				if (f[mid] < a[i]) r = mid;
				else l = mid + 1; 
			}
			//cout << f[l] << endl;
			f[l] = a[i];
		}
	}

	cout << idx << endl;
	idx = 0;
	for (int i = 1; i <= n; i ++ )
	{
		if (g[idx] < a[i])
			g[++ idx ] = a[i];
		else
		{
			int l = 0, r = idx;
			while (l < r)
			{
				int mid = (l + r) >> 1;
				if (g[mid] < a[i]) l = mid + 1;
				else r = mid;
			}
			g[l] = a[i];
		}
	}

	cout << idx << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
