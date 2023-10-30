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

void solve()
{
	int n;
	cin >> n;
	LL res = INFL;
	for (int i = 1; i <= n; i ++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		LL d = (a * a) + (b * b) + (c * c);
		res = min(res, d);
	}

	double t = sqrt(res);
	printf("%.03lf\n", t);
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
