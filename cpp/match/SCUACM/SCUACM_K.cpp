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

const int N = 25;
int a[N], b[N];
bool st[N];
int n, x, ans = INF;

void dfs(int u, int res)
{
    if (res >= ans)
        return ;
	if (u >= n)
	{
		ans = min(ans, res);
        return ;
    }

	for (int i = 1; i <= n; i ++ ) 
	{
		if (!st[i] && a[i] >= res) 
        {
			st[i] = true;
			b[u] = i;
            LL q = a[i] / res;
            LL r = a[i] % res;
			dfs(u + 1, res + q * (a[i] + r));
			st[i] = false;
			b[u] = 0;
		}
        if (res > a[n])
        {
            ans = min(res, ans);
        }
	}

}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
    {
		scanf("%d", &a[i]);
    }
	scanf("%d", &x);
    sort(a + 1, a + n + 1);
    if (x > a[n])
    {
        cout << x << endl;
        return ;
    }

    int res = x;
	dfs(0, res);

	printf("%d\n", ans);

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}