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
	if (n <= 2)
	{
		cout << -1 << endl;
		return ;
	}
	if (n % 3 == 0)
	{
		int x = 1, y = 1;
		while (n)
		{
			cout << x << " " << y << endl;
			cout << x << " " << y << endl;
			cout << x + 1 << " " << y << endl;
			y = y + 2;
			n = n - 3;
		}
		return ;
	}
	if (n % 3 == 1)
	{
		int t = n / 3 - 1, x = 1, y = 1;
		while (t -- )
		{
			cout << x << " " << y << endl;
			cout << x << " " << y << endl;
			cout << x + 1 << " " << y << endl;
			y = y + 2;
			n = n - 3;
		}
		cout << x << " " << y << endl;
		cout << x + 1 << " " << y << endl;
		cout << x << " " << y + 1 << endl;
		cout << x + 1 << " " << y + 1 << endl;
		return ;
	}
	if (n % 3 == 2)
	{
		int t = n / 3;
		if (t < 2)
		{
			cout << -1 << endl;
			return ;
		}
		t = t - 2;
		int x = 1, y = 1;
		while (t -- )
		{
			cout << x << " " << y << endl;
			cout << x << " " << y << endl;
			cout << x + 1 << " " << y << endl;
			y = y + 2;
			n = n - 3;
		}
		for (int i = 1; i <= 2; i ++ )
		{
			cout << x << " " << y << endl;
			cout << x + 1 << " " << y << endl;
			cout << x << " " << y + 1 << endl;
			cout << x + 1 << " " << y + 1 << endl;
			y = y + 3;
		}

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
