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

const int N = 110;
int a[N];

void solve()
{
	int n;
	cin >> n;
	memset(a, -1, sizeof a);
	a[1] = 0;
	string str;
	int t = 1;
	while (1)
	{
		for (int i = 1; i <= n; i ++ )
			cout << a[i] << " ";
		cout << endl;
		fflush(stdout);
		cin >> str;
		if (str == "RE")
		{
			t ++ ;
			a[t] = 0;
		}
		if (str == "WA")
		{
			a[t] = 1;
			t ++ ;
			a[t] = 0;
		}
		if (str == "AC")
			break;
	}
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
