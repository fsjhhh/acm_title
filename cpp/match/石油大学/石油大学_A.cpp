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

const int N = 1e6 + 10;

void solve()
{
	string s;
	cin >> s;
    string a;
    int res = 0;
	for (int i = 0; i < s.size(); i ++ )
    {
        if (s[i] != '0')
        {
            res += (s[i] - '0');
        }
        if (s[i] == '0')
        {
            if (res == 0)
                continue;
            cout << (char)('a' + res - 1);
            res = 0; 
        }
    }
    if (res != 0)
        cout << (char)('a' + res - 1);
    cout << endl;

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
