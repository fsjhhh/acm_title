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
#include <iomanip> // std::fixed std::setprecision(x) 保留x位小数
#include <array>
#include <bitset>
#include <functional>
#include <ranges>
//#include <bits/stdc++.h>
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    LL n;
    std::cin >> n;
    std::multiset<LL> s;
    LL ans = 0;
    for (LL i = 1; i <= n; i++) {
        LL te;
        std::cin >> te;
        s.insert(te);
    }
    LL z = 0;
    while (!s.empty())
    {
        LL s1 = *s.begin(), s2 = *(--s.end());
        if (s.size() == 1)
        {
            LL s3 = s2 - z;
            ans += (s3 + 1) / 2;
            s2 -= (s3 + 1) / 2;
            if (s2 > 0) ans++;
            s.erase(s.begin());
            continue;
        }
        if (z >= s2)
        {
            z = 0;
            ans++;
            s.erase(--s.end());
            continue;
        }
        if (s1 + z < s2)
        {
            z += s1;
            ans += s1;
            s1 = 0;
        }
        else
        {
            LL te = s2 - z;
            s1 -= te;
            ans += te;
            z += te;
        }
        s.erase(s.begin());
        if (s1) s.insert(s1);
    }
    std::cout << ans << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
