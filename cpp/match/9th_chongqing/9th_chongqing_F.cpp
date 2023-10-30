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
	int x, y, m;
	cin >> x >> y >> m;

	int a = m / x, b = m / y;
	int res = 0;
	for (int i = 0; i <= a; i ++ )
	{
		for (int j = 0; j <= b; j ++ )
		{
			if (x * i + y * j <= m)
			{
				res = max(res, x * i + y * j);
			}
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
