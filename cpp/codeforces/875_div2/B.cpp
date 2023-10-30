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

const int N = 1e6 + 10;
std::vector<int> a, b, s1, s2;

void solve()
{
    a.clear();
    b.clear();
    s1.clear();
    s2.clear();
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        a.push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
        b.push_back(x);
    }
    for (int i = 0; i <= 2 * n; i++)
    {
        s1.push_back(0);
        s2.push_back(0);
    }
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n - 1 && a[j + 1] == a[i])
            j++;
        s1[a[i]] = std::max(s1[a[i]], j - i + 1);
        i = j + 1;
    }
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n - 1 && b[j + 1] == b[i])
            j++;
        s2[b[i]] = std::max(s2[b[i]], j - i + 1);
        i = j + 1;
    }
    int ans = 0;
    for (int i = 0; i <= 2 * n; i++)
        ans = std::max(ans, s1[i] + s2[i]);
    std::cout << ans << std::endl;
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