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
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

using namespace std;

const int N = 1e4 + 10;
bool st[N];
int n, m;
bool pd = false;

void dfs(int u)
{
	if (u == n) {
		pd = true;
		return ;
	}
	int k;
	cin >> k;
	vector<int> q(k + 1);
	for (int i = 1; i <= k; i ++ ) {
		cin >> q[i];
	}
	for (int i = 1; i <= k; i ++ )
	{
		int it = q[i];
		if (!st[it])
		{
			cout << it << endl;
			st[it] = true;
			dfs(it);
			if (pd)
				return ;
			cout << u << endl;
			int k1, _;
			cin >> k1;
			for (int j = 1; j <= k1; j ++ )
				cin >> _;
		}
	}
}

void solve()
{
    cin >> n >> m;
    st[1] = true;
    dfs(1);
}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}