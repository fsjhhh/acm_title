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

std::string s;

void solve()
{
    std::cin >> s;
    // std::cout << s << "\n";
    int r = -1;
    for (int i = s.size() - 1; i >= 0; i -- )
    {
        if (s[i] == 'A')
        {
            r = i;
            break;
        }
    }
    if (r == -1)
    {
        std::cout << 0 << "\n";
        return ;
    }
    
    int ans = 0;
    for (int i = 0; i <= r; i ++ )
    {
        if (s[i] == 'C')
        {
            s[i] = 'A';
            ans ++ ;
        }
    }
    for (int i = s.size(); i >= 0; i -- )
    {
        if (s[i] == 'A')
        {
            s[i] = 'C';
            ans -- ;
        }
        if (ans == 0)
            break;
    }
    // std::cout << s << "\n";
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); i ++ )
    {
        if (s[i] == 'A')
            a ++ ;
        if (s[i] == 'B' && b < a)
            b ++ ;
        if (s[i] == 'C' && c < b)
            c ++ ;
    }
    std::cout << c << "\n";
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

