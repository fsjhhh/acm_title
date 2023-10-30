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

char a[7][5];

void solve()
{
	for (int i = 1; i <= 6; i ++ )
		for (int j = 1; j <= 4; j ++ )
			cin >> a[i][j];

	int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	PII s1[4], s2[4];
	int idx1 = 0, idx2 = 0;
	for (int i = 1; i <= 3; i ++ )
	{
		for (int j = 1; j <= 4; j ++ )
		{
			if (i == 1 && a[i][j] != '0')
				t1 = a[i][j] - '0';
			if (i == 3 && a[i][j] != '0')
				t2 = a[i][j] - '0';
		}
		if (i == 2)
		{
			s1[++ idx1 ] = {(a[i][1] - '0'), (a[i][3] - '0')};
			s1[++ idx1 ] = {(a[i][2] - '0'), (a[i][4] - '0')};
		}
	}
	s1[++ idx1 ] = {t1, t2};

	for (int i = 4; i <= 6; i ++ )
	{
		for (int j = 1; j <= 4; j ++ )
		{
			if (i == 4 && a[i][j] != '0')
				t3 = a[i][j] - '0';
			if (i == 6 && a[i][j] != '0')
				t4 = a[i][j] - '0';
		}
		if (i == 5)
		{
			s2[++ idx2 ] = {(a[i][1] - '0'), (a[i][3] - '0')};
			s2[++ idx2 ] = {(a[i][2] - '0'), (a[i][4] - '0')};
		}
	}
	s2[++ idx2 ] = {t3, t4};

	sort(s1 + 1, s1 + idx1 + 1);
	sort(s2 + 1, s2 + idx2 + 1);

	int res = 0;
	for (int i = 1; i <= 3; i ++ )
	{
		//cout << s1[i].first << " " << s1[i].second << endl;
		//cout << s2[i].first << " " << s2[i].second << endl;
		if (s1[i].first == s2[i].first && s1[i].second == s2[i].second)
			res ++ ;
		else
		{
			cout << "NO" << endl;
			return ;
		}
	}

	if (res == 3)
		cout << "YES" << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
