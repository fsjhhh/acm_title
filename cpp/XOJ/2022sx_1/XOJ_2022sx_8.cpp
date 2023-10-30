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
       int a, b;
    cin >> a >> b;

    vector<int> c;
    for (int x = -10000; x <= 10000; x ++ )
    {
    	if (x == (sqrt(a * x) + b))
    		c.push_back(x);
    }
    int n = c.size();

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << c[i] << (i < n - 1 ? " " : "\n");
    }
	
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
