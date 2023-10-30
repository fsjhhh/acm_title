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

const int N = 510;
int d[N][N];
int p[N];
LL ans[N];
bool st[N];

void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			cin >> d[i][j];

	for (int i = 1; i <= n; i ++ )
		cin >> p[i];

	for (int i = n; i > 0; i -- )
	{
		int k = p[i];
		st[k] = true;

		for (int t = 1; t <= n; t ++ )
			for (int j = 1; j <= n; j ++ )
				d[t][j] = min(d[t][j], d[t][k] + d[k][j]);

		for (int t = 1; t <= n; t ++ )
			for (int j = 1; j <= n; j ++ )
				if (st[t] && st[j])
					ans[i] += d[t][j];	
	}

	for (int i = 1; i <= n; i ++ )
		cout << ans[i] << " ";

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
