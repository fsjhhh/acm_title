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

std::vector<LL> p;

void solve()
{
    LL n, ans = 0, cnt = 0;
    std::cin >> n;   
    auto x = std::upper_bound(p.begin(), p.end(), n);
    if (x == p.begin())
        std::cout << "-1" << std::endl;
    else
        std::cout << *prev(x) << std::endl;
}

int main()
{
    IOS;
    int x = 61;
    for (int i = 0; i < 61; i ++ )
        for (int j = 0; j < i; j ++ )
            for (int k = 0; k < j; k ++ )
                p.push_back((1LL << i) + (1LL << j) + (1LL << k));
    std::sort(p.begin(), p.end());
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}