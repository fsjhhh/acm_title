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

const int N = 5e5 + 10;
int h[N], e[N], ne[N], idx;
int q[N], d[N], st[N], w[N];
int n, m;

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool topsort() {
	int hh = 0, tt = -1;
	for (int i = 1; i <= n; i ++ ) {
		if (!d[i]) {
			q[++ tt ] = i;
		}
	}

	while (hh <= tt) {
		int t = q[hh ++ ];
		for (int i = h[t]; i != -1; i = ne[i]) {
			int x = e[i];
			if (w[t])
			{
				w[x] = 1;
				if (w[x] && st[x])
				{
					return false;
				}
			}
			d[x] -- ;
			if (d[x] == 0) {
				q[++ tt ] = x;
			}
		}
	}
	if (tt == n - 1) {
		return true;
	}
	else {
		return false;
	}

}

void solve()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m -- ) {
		int a, b;
		cin >> a >> b;
		if (a == b) 
		{
			st[a] ++ ;
			w[a] = 1;
			continue;
		}
		add(a, b);
		d[b] ++ ;
	}
	for (int i = 1; i <= n; i ++ )
	{
		if (st[i] >= 2)
		{
			cout << "Yes" << endl;
			return ;
		}
	}

	if (topsort()) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
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
