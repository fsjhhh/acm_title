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
char ls[N];
std::string s;
int a[N], b[N];

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::cin >> s;
    s = "." + s;
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
    	ls[i] = '.';
    }
    for (int i = 1; i <= n; i ++ ) {
    	if (ls[a[i]] == '.') {
    		b[a[i]] = i;
    		ls[a[i]] = s[i]; 
    	}
    	else {
    		char x = s[i];
    		s[i] = ls[a[i]];
    		ls[a[i]] = x;
    	}
    }
    for (int i = 1; i <= m; i ++ ) {
    	s[b[i]] = ls[i];
    }
    for (int i = 1; i <= n; i ++ ) {
        std::cout << s[i];
    }
    std::cout << "\n";
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