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

char a[10][10];

void solve()
{
    int x, y;
    for (int i = 1; i <= 8; i ++ ) {
        for (int j = 1; j <= 8; j ++ ) {
            std::cin >> a[i][j];
            if (a[i][j] == '*') {
                x = i, y = j;
            }
        }
    }

    std::cout << (char)(y - 1 + 'a') << 8 - x + 1 << "\n";

}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}