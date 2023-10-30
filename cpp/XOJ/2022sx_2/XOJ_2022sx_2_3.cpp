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

set<string> s;
int a[1010];

void solve()
{
	int n, m;
	cin >> n >> m;
	while (m -- )
	{
		string str;
		cin >> str;
		if (!s.count(str))
			s.insert(str);
	}

	int cnt = 0;
	for (auto it : s)
		a[++ cnt ] = it.size();

	sort(a + 1, a + cnt + 1);
	int res = 0;
	for (int i = 1; i <= cnt; i ++ )
	{
		if (n - a[i] >= 0)
		{
			res ++ ;
			n -= a[i];
		}
		if (n - a[i] < 0)
			break;
		if (n == 0)
			break;
		n -- ;
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
