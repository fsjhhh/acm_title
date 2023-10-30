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

void solve()
{
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    int a_1 = 0, b_1 = 0;
    for (int i = 0; i < n; i ++ ) {
    	if (a[i] == '1') {
    		a_1 ++ ;
    	}
    	if (b[i] == '1') {
    		b_1 ++ ;
    	}
    }
    int _1 = std::min(a_1, n - b_1) + std::min(n - a_1, b_1);
    for (int i = 0; i < _1; i ++ ) {
    	std::cout << "1";
    }
    for (int i = _1; i < n; i ++ ) {
    	std::cout << "0";
    }
    std::cout << "\n";
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