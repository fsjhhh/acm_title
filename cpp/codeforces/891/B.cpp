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
    int i;
    if (s[0] >= '5')
    {
        std::cout << 1;
        for (int i = 1; i <= s.size(); i ++ )
            std::cout << 0;
        std::cout << "\n";
        return;
    }
    for (i = 0; i < s.size(); i ++ )
    {
        if (s[i] >= '5')
        {
            s[i] = '0';
            s[i - 1] += 1;
            break;
        }
    }
    for (int j = i; j < s.size(); j ++ )
        s[j] = '0';
    for (; i > 0; i -- )
    {
        if (s[i] >= '5')
        {
            s[i - 1] ++ ;
            s[i] = '0';
        }
    }
    if (s[0] >= '5')
    {
        std::cout << 1;
        for (int i = 1; i <= s.size(); i ++ )
            std::cout << 0;
    }
    else
    {
        std::cout << s;
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