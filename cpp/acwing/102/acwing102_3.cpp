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
LL a[N];
std::map<LL, LL> mp1, mp2;

void solve()
{
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    LL res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % k == 0)
        {
            res += mp2[a[i] / k];
            mp2[a[i]] += mp1[a[i] / k];
        }
        mp1[a[i]]++;
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