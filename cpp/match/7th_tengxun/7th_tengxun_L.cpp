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
// priority_queue 优先队列
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
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int ans = 0;
        if (s[i] > '0' && s[i] <= '9')
        {
            j = i;
            while (s[j] >= '0' && s[j] <= '9')
            {
                ans = ans * 10 + s[j] - '0';
                j++;
            }
            std::string s1;
            for (; (s[j] < '0' || s[j] > '9') && j < s.size(); j++)
            {
                s1 += s[j];
            }
            for (int k = 1; k <= ans; k++)
            {
                std::cout << s1;
            }
            i = j - 1;
        }
    }
    std::cout << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}