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
#define IOS ios::sync_with_stdio(0); \
            cin.tie(0);              \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10;
LL a[N], s[N];

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	} 

	for (int j = 1; j <= m; j ++ ) {
		cin >> s[j];
	}

	for (int i = 1, j = 1; i <= m; i ++ ) {
		if (s[i] == a[j]) {
			j ++ ;
			if (j == n + 1) {
				cout << "Yes" << endl;
				return ;
			}
		}
	}

	cout << "No" << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
