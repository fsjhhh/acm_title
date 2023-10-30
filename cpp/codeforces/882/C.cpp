// #include <iostream>
// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <cmath>
// #include <vector>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <unordered_set>
// #include <queue>
// #include <deque>
// //priority_queue 优先队列
// #define IOS                           \
//     std::ios::sync_with_stdio(false); \
//     std::cin.tie(0);                  \
//     std::cout.tie(0);

// typedef long long LL;
// typedef std::pair<int, int> PII;
// typedef std::pair<LL, LL> PLL;
// const int INF = 0x3f3f3f3f;
// const LL INFL = 0x3f3f3f3f3f3f3f3f;

// const int N = 1e5 + 10;
// int a[N];

// void solve()
// {
//     int n;
//     std::cin >> n;
//     for (int i = 1; i <= n; i ++ )
//         std::cin >> a[i];
//     std::set<int> s;
//     int ans = 0;
//     s.insert(0);
//     for (int i = 1; i <= n; i ++ )
//     {
//         a[i] ^= a[i - 1];
//         for (auto j : s)
//         {
//             ans = std::max(ans, a[i] ^ j);
//         }
//         s.insert(a[i]);
//     }
//     s.clear();
//     std::cout << ans << "\n";
// }

// int main()
// {
//     IOS;
//     int t = 1;
//     std::cin >> t;
//     while (t -- )
//         solve();
//     return 0;
// }



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

const int N = 1e5 + 10;
int a[N], pd[1 << 8];

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        std::cin >> a[i];
    }
    pd[0] = true;
    int maxx = 0;
    for (int i = 1; i <= n; i++) 
    {
        a[i] ^= a[i - 1];
        for (int j = 0; j < (1 << 8); j ++ )
        {
            if (pd[j])
                maxx = std::max(maxx, j ^ a[i]);
        }
        pd[a[i]] = true;
    }
    memset(pd, 0, sizeof pd);
    std::cout << maxx << "\n"; 
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

