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

const int N = 2010;
int a[N][N];
int f[N][N];
int n, m;

void solve()
{
	cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> a[i][j];

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
        {
            f[i][j] = f[i - 1][j] + a[j][i];
            if (j == 1)
                f[i][j] = min(f[i][j], f[i - 1][m] + a[j][i]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + a[j][i]);
        }
    }

    int res = 2000000010;
    for (int i = 1; i <= m; i ++ )
    {
        res = min(res, f[n][i]);
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
