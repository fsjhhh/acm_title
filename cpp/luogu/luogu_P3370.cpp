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
typedef unsigned long long ULL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const ULL base = 131;
const ULL mod1 = 805306457, mod2 = 1610612741;

ULL hash_1(std::string s) {
    int len = s.size();
    ULL ans = 0;
    for (int i = 0; i < len; i++) {
        ans = (ans * base + (ULL)s[i]) % mod1;
    }
    return ans;
}

ULL hash_2(std::string s) {
    int len = s.size();
    ULL ans = 0;
    for (int i = 0; i < len; i++) {
        ans = (ans * base + (ULL)s[i]) % mod2;
    }
    return ans;
}

void solve() {
    int n;
    std::cin >> n;
    std::map<std::pair<ULL, ULL>, int> mp;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        ULL z1 = hash_1(s), z2 = hash_2(s);
        mp[{z1, z2}] ++ ;
    }
    std::cout << mp.size() << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
