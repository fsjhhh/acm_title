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

const int N = 3e5 + 10;
string s;
char tree[N][2];
int idx;
bool st[N];

void solve()
{
	cin >> s;
	for (int i = 0; i < s.size(); i ++ )
	{
		if (s[i] == '(')
		{
			tree[++ idx ][0] = '(';
		}
		if (s[i] == ')')
		{
			tree[idx][1] = ')';
			if (idx == 1)
			{
				if (i == s.size() - 1)
				{
					cout << "YES" << endl;
				}
				else
				{
					cout << "NO" << endl;
				}
			}
		}

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
