// 求斜率k
/*
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

set<double> s;

void solve()
{
	int n, x, y;
	cin >> n >> x >> y;

	double k = 0;
	bool pd = false;
	while (n -- )
	{
		int a, b;
		cin >> a >> b;
		if (a - x == 0) pd = true;
		else 
		{
			k = ((b - y) * 1.0) / ((a - x) * 1.0);
			if (!s.count(k)) s.insert(k);
		}
	}

	if (pd) cout << s.size() + 1 << endl;
	else cout << s.size() << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
*/

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

set<PII> s;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

void solve()
{
	int n, x, y;
	cin >> n >> x >> y;
	while (n -- )
	{
		int a, b;
		cin >> a >> b;
		a -= x, b -= y;
		int d = gcd(a, b);
		a /= d, b /= d;
		if (a < 0) a = -a, b = -b;
		s.insert({a, b});
	}

	cout << s.size() << endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
