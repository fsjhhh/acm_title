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

const int N = 1010;
int a[N][N], f[N][N];

void solve()
{
	int r;
	cin >> r;
	for (int i = 1; i <= r; i ++ )
		for (int j = 1; j <= i; j ++ )
			cin >> a[i][j];

	for (int i = 1; i <= r; i ++ )
	{
		f[i][0] = -0x3f3f3f3f;
		f[i][i + 1] = -0x3f3f3f3f;
	}

	for (int i = 1; i <= r; i ++ )
	{
		for (int j = 1; j <= i; j ++ )
		{
			f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]) + a[i][j];
		}
	}

	int res = -0x3f3f3f3f;
	for (int i = 1; i <= r; i ++ )
	{
		res = max(res, f[r][i]);
	}

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
