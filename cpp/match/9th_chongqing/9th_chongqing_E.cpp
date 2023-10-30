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

const int N = 1010, M = 1e6;
int a[N], s[N];
int n, x;

bool check(int b)
{
	int res = 0, sum = 0;
	for (int i = 1; i <= n; i ++ )
	{ 
        if (b < a[i])
            return false;
        sum += a[i];
		if (sum > b)
		{
			sum = a[i];
			res ++ ;
		}
       
	}
	if (res + 1 <= x)
		return true;
	else
		return false;
}

void solve()
{
	cin >> n >> x;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];
    
    if (x == 0)
    {
        cout << 0 << endl;
        return;
    }
        
	int l = 1, r = M;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << l << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
