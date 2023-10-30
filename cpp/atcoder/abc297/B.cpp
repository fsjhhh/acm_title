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
    std::string s;
    std::cin >> s;
    bool pd1 = false, pd2 = false;
    int r = 0;
    int b1, b2;
    for (int i = 0; i < s.size(); i ++ )
    {
        if (s[i] == 'B' && !pd1)
        {
            b1 = i + 1;
            pd1 = true;
        }
        if (s[i] == 'B' && pd1)
            b2 = i + 1;
        if (s[i] == 'R')
            r ++ ;
        if (s[i] == 'K')
        {
            if (r == 1)
                pd2 = true;
        }
    }
    if (b1 % 2 != b2 % 2 && pd2)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}