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

const int N = 1e6 + 10;
int b[N][3], sum[N][3];
int h[N], e[2 * N], ne[2 * N], idx;
int n, ro;
bool st[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u)
{
	if (h[u] == -1)
	{
		return ;
	}
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (st[j] == false)
		{
			st[j] = true;
			dfs(j);
			st[j] = false;
			for (int t = 0; t < 3; t ++ )
			{
				sum[u][t] = (sum[u][t] + sum[j][t] + b[j][t]);
			}
		}
	}

}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> ro;
	for (int i = 1; i < n; i ++ )
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
        add(b, a);
	}

	for (int i = 1; i <= n; i ++ )
	{
		int t;
		cin >> t;
		b[i][t] ++ ;
	}
    st[ro] = true;
	dfs(ro);

	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 0; j < 3; j ++ )
			cout << sum[i][j] << " ";
		cout << endl;
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
