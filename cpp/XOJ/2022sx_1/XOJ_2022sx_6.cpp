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
	LL n, m;
	cin >> n >> m;
	LL t = min(n, m);
	LL res = 0;
	for (int i = 1; i <= t; i ++ )
	{
		res += ((n - i + 1) * (m - i + 1) * i);
	}

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
