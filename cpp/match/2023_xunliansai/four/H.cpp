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
// #include <bits/stdc++.h>
// priority_queue 优先队列
// std::cout.flush(); 交互题
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

void solve()
{
    std::string str, s;
    std::cin >> str >> s;
    if (s.size() == 1 && str.size() > 1) {
        std::cout << "NO\n";
        return ;
    }
    if ((str.size() - s.size()) & 1) {
        std::cout << "NO\n";
        return ;
    }
    if (s[0] != str[0] || s[s.size() - 1] != str[str.size() - 1]) {
        std::cout << "NO\n";
        return ;
    }
    str = str.substr(1, str.size() - 2);
    s = s.substr(1, s.size() - 2);
    int i = 0, j = 0;
    while (i < str.size() && j < s.size()) {
        if (str[i] == s[j]) {
            i++;
            j++;
        }
        else {
        	i += 2;
        }
    }
    if (j == s.size()) {
    	std::cout << "YES\n";
    }
    else {
    	std::cout << "NO\n";
    }
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}