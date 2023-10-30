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

const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];
vector<int> v[N];
int n, m;

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int add_dis(int ver, int di)
{
	for (int x : v[ver])
	{
		if (x == di) di ++ ;
		else if (x > di)
			break;
	}

	return di;
}

void dijkstra()
{
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, 1});
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	while (q.size())
	{
		PII t = q.top();
		q.pop();

		int di = t.first, ver = t.second;
		if (st[ver]) continue;
		st[ver] = true;
		di = add_dis(ver, di);
		for (int i = h[ver]; i != -1; i = ne[i] )
		{
			int j = e[i];
			if (dist[j] > di + w[i])
			{
				dist[j] = di + w[i];
				q.push({dist[j], j});
			}
		}

	}

}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m -- )
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}

	for (int i = 1; i <= n; i ++ )
	{
		int k;
		cin >> k;
		while (k -- )
		{
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}

	dijkstra();

	if (dist[n] == INF) cout << "-1" << endl;
	else cout << dist[n] << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
