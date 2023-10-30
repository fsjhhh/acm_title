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

const int N = 110;
int n, m;
int v[N][N], w[N][N], s[N];
int dp[N];

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
    {
    	cin >> s[i];
    	for(int j = 1; j <= s[i]; j ++ )
    		cin >> v[i][j] >> w[i][j];
    }

    for(int i = 1; i <= n; i ++ )
    	for(int j = m; j >= 0; j -- )
    		for(int k = 1; k <= s[i]; k ++ )
    			if(j >= v[i][k]) dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);

    cout << dp[m] << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();
        
    return 0;
}
