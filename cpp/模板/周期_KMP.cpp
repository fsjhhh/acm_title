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

const int N = 1e6 + 10;
char s[N];
int ne[N];

void solve()
{
	 int n, t = 1;
	 while (1) {
	 	cin >> n;
	 	if (n == 0) {
	 		return ;
	 	}

	 	cin >> s + 1;
	 	for (int i = 2, j = 0; i <= n; i ++ ) {
	 		while (j && s[i] != s[j + 1]) {
	 			j = ne[j];
	 		}
	 		if (s[i] == s[j + 1]) j ++ ;
	 		ne[i] = j;
	 	}

	 	cout << "Test case #" << t ++ << endl;
	 	for (int i = 1; i <= n; i ++ ) {
	 		int m = i - ne[i];
	 		if (i % m == 0 && i / m > 1) {
	 			cout << i << " " << i / m << endl;
	 		}
	 	}

	 	cout << endl;

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
