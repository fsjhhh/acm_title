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

const int N = 1e5 + 10;
LL a[N];

void solve()
{
 	int n;
 	std::cin >> n;
 	std::map<int, int> mp;
    LL sum = 0;   
 	for (int i = 1; i <= n; i ++ ) {
        std::cin >> a[i];
        sum += a[i];
    }
    if (n == 1) {
        std::cout << "NO" << "\n";
        return ;
    }
    LL _1 = 0, _2 = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i] == 1) {
            _1 ++ ;
        }
        else {
            _2 += (a[i] - 2 + 1);
        }
    }
    if (_2 >= _1) {
        std::cout << "YES" << "\n";
    }
    else {
        std::cout << "NO" << "\n";
    }
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