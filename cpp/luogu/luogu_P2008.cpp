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

const int N = 1e4 + 10;
int a[N], v[N];
int f[N];

void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i], v[i] = a[i];

	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j < i; j ++ )
		{
			if (a[i] >= a[j] && f[i] < f[j] + 1)
			{
				f[i] = f[j] + 1;
				v[i] = v[j] + a[i];
			}
		}

		cout << v[i] << " ";
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
