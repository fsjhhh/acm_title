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
	LL a, b, n;
	cin >> a >> b >> n;
	if (a < b)
	{
		cout << b * n << endl;
	}
	else
	{
		LL res = 0;
		if (n % 2 == 0)
		{
			res = n * b + (a - b) * (n / 2 - 1);
		}
		else
		{
			LL t = n / 2;
			res = t * (a + b);
			res = res + b;
		}
		cout << res << endl;
	}
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
