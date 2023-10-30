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

const int N = 1e6 + 10, mod = 1e9;
int f[N], n;

void solve()
{
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; i *= 2)
	{
		for (int j = i; j <= n; j ++ )
		{
			f[j] = (f[j] + f[j - i]) % mod;
		}
	}

	cout << f[n] << endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
