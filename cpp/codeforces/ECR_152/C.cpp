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

const int N = 2e5 + 10;
int sum[N], pos[N], pos1[N];

void solve()
{
    memset(sum, 0, sizeof sum);
    memset(pos, 0, sizeof pos);
    int n, q;
    std::string s;
    std::cin >> n >> q >> s;
    s = " " + s;
    int ls = 0;
    for (int i = 1; i <= n; i ++ ) {
    	if (s[i] == '1') {
    		sum[i] = sum[i - 1];
    		pos[i] = ls;
    	}
    	else {
    		sum[i] = sum[i - 1] + 1;
    		pos[i] = i;
    		ls = i;
    	}
    }
    ls = n + 1;
    for (int i = n; i >= 0; i -- ) {
        if (s[i] == '1') {
            pos1[i] = i;
            ls = i;
        }
        else {
            pos1[i] = ls;
        }
    }

    LL ans = 0;
    bool pd = false;
    std::set<PII> se;
    while (q -- ) {
    	int l, r;
    	std::cin >> l >> r;
    	int num = (sum[r] - sum[l - 1]);
    	int to = pos[r];
        int tot = pos1[l];
        if (tot > to)
            tot = n + 2, to = n + 2;
        if (se.find({tot, to}) != se.end()) {
            continue;
        }
        ans ++ ;
        se.insert({tot, to});

    }
    std::cout << ans << "\n";
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}