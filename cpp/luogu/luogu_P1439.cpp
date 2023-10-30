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

const int N = 1e5 + 10;
int a[N], b[N], f[N], mp[N];

void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++ ) 
	{
		cin >> a[i];
		mp[a[i]] = i;
	}
	for (int i = 1; i <= n; i ++ ) cin >> b[i];

	memset(f, 0x3f, sizeof f);
	f[0] = 0;

	int idx = 0;
	for (int i = 1; i <= n; i ++ )
	{
		if (mp[b[i]] > f[idx]) 
			f[++ idx] = mp[b[i]];
		else
		{
			int l = 0, r = idx, x = mp[b[i]];
			while (l < r)
			{
				int mid = l + r >> 1;
				if (f[mid] >= x) r = mid;
				else l = mid + 1;
			}
			f[l] = x;
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
