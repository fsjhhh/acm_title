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

const int N = 110, mod = 998244353;
LL a[N];

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = n; i >= 0; i -- )
		cin >> a[i];

	for (int i = 1; i <= m; i ++ )
		for (int i = 0; i <= n; i ++ )
			a[i] = a[i +  1] * (i + 1) % mod;

	for (int i = 1; i <= m; i ++ )
		cout << 0 << " ";
	for (int i = n - m; i >= 0; i -- )
		cout << a[i] << " ";

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
