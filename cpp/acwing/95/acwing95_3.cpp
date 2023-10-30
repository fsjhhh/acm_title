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

void solve()
{
	int t;
	cin >> t;
	while (t -- )
	{
		int n;
		cin >> n;
		int f, minn;
		for (int i = 1; i <= n; i ++ )
		{
			int x;
			cin >> x;
			if (i == 1)
			{
				f = x;
				minn = x;
			}
			else
				minn = min(x, minn);
		}

		if (f <= minn) cout << "Bob" << endl;
		else cout << "Alice" << endl;

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
