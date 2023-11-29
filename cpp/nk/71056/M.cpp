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

bool cmp(PII a, PII b)
{
    if (a.first != b.first)
        return a.first > b.first;
    else
        return a.second > b.second;
}

void solve()
{
    int n;
    std::cin >> n;
    std::vector<PII> v(n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        v[i] = {a, b};
    }
    std::sort(v.begin() + 1, v.end(), cmp);
    int q;
    std::cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a > v[c].first)
        {
            std::cout << "YES" << "\n";
            continue;
        }
        else if (a == v[c].first && b >= v[c].second)
        {
            std::cout << "YES" << "\n";
            continue;
        }
        else
            std::cout << "NO" << "\n";
    }
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
