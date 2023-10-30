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

const int N = 5e5 + 10;
int a[N];

bool cmp(int a, int b)
{
	return a > b;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i ++ )
		cout << a[i] << " ";
	cout << endl;
	cout << m - n - 1 << " ";
	for (int i = 1; i < n; i ++ )
		cout << 1 << " ";
	cout << endl;
	
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
