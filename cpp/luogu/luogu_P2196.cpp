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

const int N = 30;
bool st[N][N], pd = false;
int a[N], n, res = 0;
int b[N], idx;
int step[N], w[N];

bool check(int x)
{
	for (int i = x; i <= n; i ++ )
	{
		if (st[x][i] && !b[i])
			return false;
	}

	return true;
}

void dfs(int u, int s, int ans)
{
	if (check(u))
	{
		if (res < ans)
		{
			res = ans;
			idx = s;
			for (int i = 1; i <= s; i ++ )
				w[i] = step[i];
		}
		return ;
	}

	for (int i = u; i <= n; i ++ )
	{
		if (st[u][i] && !b[i])
		{
			b[i] = 1;
			step[s + 1] = i;
			dfs(i, s + 1, ans + a[i]);
			b[i] = 0;
		}
	}

}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];

	for (int i = 1; i <= n; i ++ )
	{
		for (int j = i + 1; j <= n; j ++ )
		{
			int x;
			cin >> x;
			if (x == 1)
				st[i][j] = true;
		}
	}

	for (int i = 1; i <= n; i ++ )
	{
		b[i] = 1;
		step[1] = i;
		dfs(i, 1, a[i]);
		b[i] = 0;
	}

	for (int i = 1; i <= idx; i ++ )
		cout << w[i] << " ";
	cout << endl;
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
