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
    int a, b, c;
    std::cin >> a >> b >> c;
    std::vector<int> q = {a, b, c};
    std::sort(q.begin(), q.end());
    if (q[0] + q[1] == q[2]) {
    	std::cout << "Yes" << "\n";
        return ;
    }
    if ((q[0] == q[1] && q[2] % 2 == 0) || (q[0] == q[2] && q[1] % 2 == 0) || (q[1] == q[2] && q[0] % 2 == 0)) {
        std::cout << "Yes" << "\n";
        return ;
    }
    std::cout << "No" << "\n";
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