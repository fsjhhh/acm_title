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

const int N = 1e5 + 10;
char a[N];


void solve()
{
	int n;
	scanf("%d%s", &n, a + 1);
	char minn = 'z';
 	map<int, int> ma;

 	int cnt = 0;
	for (int i = 1; i <= n; i ++ )
	{
		if (a[i] < minn)
			minn = a[i];
	}

	for (int i = 1; i <= n; i ++ )
	{
		if (a[i] == minn)
			ma[++ cnt ] = i;
	}

	int t = 0;
	for (auto it : ma)
	{

		//cout << it.first << " " << it.second << endl;
		if (it.first != it.second)
			t = it.second;
	}

	//cout << t << endl;

	if (t == 0)
	{
		for (int i = 1; i <= n; i ++ )
			cout << a[i];
	}
	else
	{
		cout << a[t];
		for (int i = 1; i <= n; i ++ )
		{
			if (i != t)
				cout << a[i];
		}
	}

	cout << endl;

}

int main()
{
    IOS;
    int t = 1;
    scanf("%d", &t);
    while(t -- )
        solve();

    return 0;
}
