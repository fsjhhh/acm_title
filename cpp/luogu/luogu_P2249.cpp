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

const int N = 1e6 + 10;
int a[N];

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];

	while (m -- )
	{
		int x;
		cin >> x;
		int l = 1, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (a[mid] < x) l = mid + 1;
			else r = mid;
		}

		if (a[l] == x)
			cout << l << " ";
		else
			cout << -1 << " ";

	}
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
