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

const int N = 1010;
int a[N];

void solve()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	map<int, char> mp1;
	map<int, char> mp2;
	for (int i = 1; i <= n; i ++ )
		mp1[i] = str[i - 1];

	bool pd1 = false, pd2 = true;
	string s = "";
	int idx = 0;
	while (1)
	{
		idx ++ ;
		if (!pd1)
		{
			for (int i = 1; i <= n; i ++ )
			{
				s += mp1[a[i]];
				mp2[i] = mp1[a[i]];
			}
			pd1 = true;
			pd2 = false;
			if (s == str)
			{
				cout << idx << endl;
				return ;
			}
		}
		else
		{
			for (int i = 1; i <= n; i ++ )
			{
				s += mp2[a[i]];
				mp1[i] = mp2[a[i]];
			}
			pd2 = true;
			pd1 = false;
			if (s == str)
			{
				cout << idx << endl;
				return ;
			}
		}
		s = "";
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
