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

int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool pd_run(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

int sum(int x)
{
    int ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void solve()
{
    int y = 2001, m = 1, d = 1;
    int res = 0;
    while (1)
    {
        if (y == 2021 && m == 12 && d == 31)
            break;
        if (pd_run(y))
            mon[2] = 29;
        else
            mon[2] = 28;
        int a = sum(y) + sum(m) + sum(d);
        for (int i = 1; i < a; i++)
            if (i * i == a)
                res++;
        d++;
        if (d > mon[m])
        {
            m++;
            d = 1;
        }
        if (m > 12)
        {
            y++;
            m = 1;
        }
    }
    std::cout << res << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}