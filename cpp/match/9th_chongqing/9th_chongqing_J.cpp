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

int a[15], b[15];
bool st[15];
int n, x;

void dfs(int u)
{
	if (u > n)
	{
		int res1 = 0, res2 = 0;
		for (int i = 1; i <= n; i ++ )
		{
			if (b[i] - a[i] >= x)
				res1 ++ ;
			else
				res2 ++ ;
		}
		if (res1 > res2)
		{
			for (int i = 1; i <= n; i ++ )
				cout << b[i] << " ";
			cout << endl;
		}
	}

	for (int i = 1; i <= n; i ++ )
	{
		if (!st[i])
		{
			st[i] = true;
			b[u] = i;
			dfs(u + 1);
			st[i] = false;
		}
	}

}

void solve()
{
	cin >> n >> x;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];

	dfs(1);

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
