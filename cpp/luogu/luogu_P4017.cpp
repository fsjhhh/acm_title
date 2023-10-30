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

const int N = 5e3 + 10, M = 5e5 + 10, mod = 80112002;
int h[N], e[M], ne[M], idx;
int in[N], out[N];
LL lin[N];
int n, m;
LL ans = 0;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void topsort()
{
	queue<int> q;

	for (int i = 1; i <= n; i ++ )
	{
		if (in[i] == 0)
		{
			lin[i] = 1;
			q.push(i);
		}
	}

	while (q.size())
	{
		auto t = q.front();
		q.pop();

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int v = e[i];
			lin[v] = (lin[v] + lin[t]) % mod;
			in[v] -- ;
			if (in[v] == 0)
				q.push(v);
		}
	}

}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while (m -- )
	{
		int a, b;
		cin >> a >> b;
		out[a] ++ ;
		in[b] ++ ;
		add(a, b);
	}

	topsort();

	for (int i = 1; i <= n; i ++ )
	{
		if (out[i] == 0)
			ans = (ans + lin[i]) % mod;
	}

	cout << ans << endl;


}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
