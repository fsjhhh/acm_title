#include <iostream>
#include <cstring>
#include <algorithm>
#define IOS                  \
	ios::sync_with_stdio(0); \
	cin.tie(0);              \
	cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], dist[N], n, m, idx;
PII a[N];
bool st[N];

int pirm()
{
	memset(dist, 0x3f, sizeof dist);

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}

		st[t] = true;

		if (i != 1 && dist[t] == INF)
			return INF;
		if (i != 1)
		{
			res += dist[t];
			a[++idx] = {t, dist[t]};
		}
		for (int j = 1; j <= n; j++)
			dist[j] = min(dist[j], g[t][j]);
	}

	return res;
}

void solve()
{
	memset(g, 0x3f, sizeof g);
	cin >> n >> m;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c);
	}

	int t = pirm();

	if (t == INF)
		cout << "impossible" << endl;
	else
	{
		for (int i = 1; i <= idx; i++)
			cout << a[i].first << " " << a[i].second << endl;
		cout << t << endl;
	}
}

int main()
{
	IOS;
	int t = 1;
	while (t--)
		solve();

	return 0;
}
