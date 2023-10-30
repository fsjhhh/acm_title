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

const int N = 1e6 + 10, mod = 1e9 + 7;
LL f[N];

void solve()
{
	int n;
	cin >> n;
	cout << f[n] << endl;
}

int main()
{
    IOS;
    f[1] = 1, f[2] = 3;
    for (int i = 3; i < N; i ++ )
        f[i] = (f[i - 1] + 2 * f[i - 2]) % mod;
    int t = 1;
    cin >> t;
    while(t -- )
        solve();

    return 0;
}
