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
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int c = n / 2;
	if (x1 > c)
		x1 = n - x1 + 1;
	if (y1 > c)
		y1 = n - y1 + 1;
	if (x2 > c)
		x2 = n - x2 + 1;
	if (y2 > c)
		y2 = n - y2 + 1;

	int _1 = min(x1, y1);
	int _2 = min(x2, y2);

	cout << abs(_1 - _2) << endl;

}

int main()
{
    IOS;
    int t = 1;
    cin >> t;
    while(t -- )
        solve();

    return 0;
}
