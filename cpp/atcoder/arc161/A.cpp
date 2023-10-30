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

const int N = 2e5 + 10;
std::vector<int> s;

bool cmp(int a, int b)
{
    return a > b;
}

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        std::cin >> x;
        s.push_back(x);
    }
    std::sort(s.begin(), s.end(), cmp);
    int t = n / 2;
    if (s[t] == s[t - 1])
    {
        int cnt = 0;
        for (auto i : s)
        {
            if (i == s[t])
                cnt ++ ;
        }
        if (cnt > n / 2)
            std::cout << "No" << std::endl;
        else
            std::cout << "Yes" << std::endl;
    }
    else
        std::cout << "Yes" << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}