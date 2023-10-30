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

int n;
std::string s, ans;

void solve()
{
    std::cin >> n;
    std::cin >> s;

    int l = 0, r = n - 1;
    while (l < r)
    {
        if (s[l] < s[r])
        {
            ans += s[l];
            l ++ ;
        }
        else if (s[l] > s[r])
        {
            ans += s[r];
            r -- ;
        }
        else
        {
            int li = l, ri = r;
            bool pd = true;
            while (li + 1 <= ri - 1)
            {
                if (s[li + 1] < s[ri - 1])
                {
                    ans += s[l];
                    l ++ ;
                    pd = false;
                    break;
                }
                else if (s[li + 1] > s[ri - 1])
                {
                    ans += s[r];
                    r -- ;
                    pd = false;
                    break;
                }
                else
                    li ++ , ri -- ;
            }
            if (pd)
            {
                ans += s[l];
                l ++ ;
            }
        }
    }
    if (l == r)
        ans += s[l];
    std::cout << ans << "\n";

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

