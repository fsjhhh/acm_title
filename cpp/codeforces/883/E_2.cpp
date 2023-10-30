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

LL maxx = 0;
const int N = 1e4 + 10;
const LL INFLL = 1e18;
std::set<LL> s;
std::vector<LL> a;

void init()
{
    for (LL i = 2; i <= 1000000; i ++ )
    {
        LL d = i * i;
        LL x = i + 1;
        while (1)
        {
            x = x + d;
            s.insert(x);
            if (INFLL / i < d)
                break;
            d = d * i;
        }
    }
    a.push_back(0);
    for (auto i : s)
        a.push_back(i);
    a.push_back(INFL);
}

void solve()
{
    LL n;
    std::cin >> n;
    int l = 1, r = a.size();
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] < n)
            l = mid + 1;
        else
            r = mid;
    }
    if (a[l] == n)
        std::cout << "YES" << "\n";
    else
    {
        LL t = sqrt(n);
        while (t * t > n)
            t -- ;
        while ((t + 1) * (t + 1) <= n)
            t ++ ;
        if (t > 1 && t * t + t + 1 == n)
            std::cout << "YES" << "\n";
        else
            std::cout << "NO" << "\n";
    }
}

int main()
{
    IOS;
    int t = 1;
    init();
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

