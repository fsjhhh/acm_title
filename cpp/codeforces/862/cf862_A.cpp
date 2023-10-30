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

const int N = 1e3 + 10;
int a[N], b[N];

void solve()
{
	int n;
	cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

	for (int x = 0; x <= (1 << 8); x ++ )
    {
        int res = 0;
        for (int i = 1; i <= n; i ++ )
        {
            res = ((a[i] ^ x) ^ res);
            //cout << res << " ";
        }
        //cout << endl;
        //cout << res << endl;
        if (res == 0)
        {
            cout << x << endl;
            return ;
        }
    }

    cout << -1 << endl;

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
