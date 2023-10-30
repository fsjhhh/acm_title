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

const int N = 1e5 + 10;
vector<int> v;

bool cmp(int a, int b)
{
	return a > b;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), cmp);

	int res = 0, idx = 0;
	for (auto it : v)
	{
		res += it;
		idx ++ ;
		if (res >= m)
			break;
	}

	cout << idx << endl;
	v.clear();
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
