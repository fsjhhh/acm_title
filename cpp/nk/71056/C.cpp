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

int find_str(std::string s, std::string sub)
{
    int idx = 0;
    int cnt = 0;

    while ((idx = s.find(sub, idx)) != s.npos)
    {
        idx++;
        cnt++;
    }
    return cnt;
}

void solve()
{
    int n;
    std::cin>>n;
    std::string s;
    std::cin >> s;
    int ans = 0;
    ans += find_str(s, "H");
    ans += find_str(s, "HE");
    ans += find_str(s, "HEB");
    ans += find_str(s, "HEBU");
    ans += find_str(s, "HEBUT");

    std::cout << ans << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
