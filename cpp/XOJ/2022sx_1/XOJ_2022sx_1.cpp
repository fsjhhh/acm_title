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
	for (int i = 1; i <= n; i ++ )
	{
		string s;
		cin >> s;
		int a = s[0] - '0';

		if (a == 0) cout << "X";
		else if (a == 2 || a == 4 || a == 6 || a == 7) cout << "I";
		else if (a == 1 || a == 3 || a == 5) cout << "E";

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
