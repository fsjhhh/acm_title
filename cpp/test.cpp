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
// #include <iomanip> // std::fixed std::setprecision(x) 保留x位小数
// #include <array>
// #include <bitset>
// #include <functional>
// //#include <bits/stdc++.h>
// //priority_queue 优先队列
// #define IOS                           \
//     std::ios::sync_with_stdio(false); \
//     std::cin.tie(0);                  \
//     std::cout.tie(0);

// typedef long long LL;
// typedef __int128 i128;
// typedef std::pair<int, int> PII;
// typedef std::pair<LL, LL> PLL;
// const int INF = 0x3f3f3f3f;
// const LL INFL = 0x3f3f3f3f3f3f3f3f;

// struct Node {
//     int D;
//     LL Min, Max;
// };

// void solve() {
//     std::string s;
//     std::cin >> s;
//     int n = s.size();
//     LL ans = 0;
//     for (int i = 0; i < n - 1; i++) {
//         if (s[i] == s[i + 1] || s[i] == '?' || s[i + 1] == '?') {
//             ans ++ ;
//             i ++ ;
//         } 
//     }
//     std::cout << ans << "\n";

// }

// int main() {
//     IOS;
//     int t = 1;
//     // std::cin >> t;
//     while (t -- )
//         solve();
//     return 0;
// }

#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <array>

using namespace std;

typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef unsigned long long ULL;
typedef long long ll;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, mod = 998244353;

ll n, m, k, q;

void solve()
{
    cin >> n >> m;
    ll l = 1, r = n;
    if ((n - 1) * n / 2 < m)
    {
        cout << "NO" << endl;
        return;
    }
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if ((mid) * (mid + 1) / 2 + (n - mid - 1) <= m)
        {
            l = mid;
        }
        else
            r = mid - 1;
    }
    ll t = n - 1 - l;
    ll res = m - l * (l + 1) / 2;
    // std::cout << l << "\n";
    cout << "YES" << endl;
    for (int i = 1; i <= n - 2; i++)
    {
        if (i <= l)
        {
            cout << i << ' ' << i + 1 << endl;
        }
        else
        {
            cout << 1 << ' ' << i + 1 << endl;
        }
    }

    cout << res - (t - 1) << ' ' << n << endl;
    cout << 1 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;

    while (t--)
        solve();

    return 0;
}