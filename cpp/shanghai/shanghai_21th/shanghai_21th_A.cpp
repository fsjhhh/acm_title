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

int f(int l,int r,int x) { // l <= x <= r
	int cnt = 0;
	while(l <= r) {
		cnt++;
		int mid = (l + r) / 2;
		if (mid == x) break;
		if (mid < x) l = mid + 1;
		else r = mid - 1;
	}
	return cnt;
}


void solve()
{
	int l, r, x;
	cin >> l >> r >> x;
	cout << f(l, r, x) << endl;
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
