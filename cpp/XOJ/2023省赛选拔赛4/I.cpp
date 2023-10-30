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

bool f[7];

void solve()
{
    f[1] = true;
    f[4] = true;
    int a, b;
    std::cin >> a >> b;
    for (int i = 1; i <= 6; i ++ ) {
        for (int j = 1; j <= 6; j ++ ) {
            for (int k = 1; k <= 6; k ++ ) {
                if (f[i] && f[j] && !f[k] && (i + j == a && k == b)) {
                    std::cout << "Yes" << "\n";
                    return ;
                }
                if (f[i] && !f[j] && !f[k] && (i == a && j + k == b)) {
                    std::cout << "Yes" << "\n";
                    return ;
                }
                if (f[i] && f[j] && f[k] && (a == i + j + k && b == 0)) {
                    std::cout << "Yes" << "\n";
                    return ;
                }
                if (!f[i] && !f[j] && !f[k] && (a == 0 && i + j + k == b)) {
                    std::cout << "Yes" << "\n";
                    return ;
                }
            }
        }
    }
    std::cout << "No" << "\n";
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
