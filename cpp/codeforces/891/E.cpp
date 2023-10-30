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
LL a[N], b[N], num[N];

void solve()
{
    int n;
    std::cin >> n;
    std::map<LL, LL> m;
    int idx = 0;
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
    	if (m.find(a[i]) == m.end()) {
    		b[++ idx] = a[i];
    	}
    	m[a[i]] ++ ;
    }
    std::sort(b + 1, b + idx + 1);
    int cnt = 0;
    std::map<LL, LL> qi, hou;
    qi[0] = 0;
    hou[idx + 1] = 0;
    for (int i = 1; i <= idx; i ++ ) {
    	if (i == 1) {
    		qi[b[i]] = m[b[i]];
    		cnt += m[b[i]];
    		continue;
    	}
    	qi[b[i]] = qi[b[i - 1]] + (b[i] - b[i - 1]) * cnt + m[b[i]];
    	cnt += m[b[i]];
    }
    cnt = 0;
    for (int i = idx; i >= 1; i -- ) {
    	if (i == idx) {
            hou[b[i]] = m[b[i]];
    		cnt += m[b[i]];
    		continue;
    	}
    	hou[b[i]] = hou[b[i + 1]] + (b[i + 1] - b[i]) * cnt + m[b[i]];
    	cnt += m[b[i]];
    }
    // for (int i = 1; i <= idx; i ++ ) {
    //     std::cout << qi[b[i]] << " " << hou[b[i]] << "\n";
    // }
    for (int i = 1; i <= n; i ++ ) {
    	std::cout << qi[a[i]] + hou[a[i]] - m[a[i]] << " \n"[i == n];
    }
    // std::cout << "\n";
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