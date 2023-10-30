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
	int n;
	cin >> n;
	int res = 0, li = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int x;
		cin >> x;
		if (x < 0)
			res ++ ;
		if (x == 0)
			li ++ ;
	}
	if (res == 1 && n == 1)
	{
		cout << "-1" << endl;
		return ;
	}
	if (li == 0)
	{
		if (res % 2 == 0)
			cout << res / 2 << endl;
		else
			cout << res / 2 + 2 << endl;
	}
	else
	{
		if (res % 2 == 0)
			cout << res / 2 << endl;
		else
			cout << res / 2 + 1 << endl;
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
