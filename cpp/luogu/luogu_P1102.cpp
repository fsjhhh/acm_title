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

const int N = 2e5 + 10;
LL a[N];

void solve()
{
	LL n, c;
	cin >> n >> c;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];

	sort(a + 1, a + n + 1);

	LL ans = 0;
	for (int i = 1; i <= n; i ++ )
	{
		LL x = a[i] + c;
		LL l = 1, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (a[mid] < x) l = mid + 1;
			else r = mid;
		}

		if (a[l] != x)
			continue;

		LL t = l;

		l = 1, r = n;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (a[mid] > x) r = mid - 1;
			else l = mid;
		}
		//cout << t << " " << l << endl;
		ans += (l - t + 1);
	}

	cout << ans << endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
