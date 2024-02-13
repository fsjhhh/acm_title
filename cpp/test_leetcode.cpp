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
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        std::map<char, int> mp;
        for (auto it : word) {
            mp[it] ++ ;
        }
        std::vector<int> a;
        for (auto [x, y] : mp) {
            a.push_back(y);
        }

        std::sort(a.begin(), a.end(), std::greater());
        int cnt = 1, num = 0, ans = 0;
        for (auto it : a) {
            ans += it * cnt;
            num ++ ;
            if (num == 8) {
                cnt ++ ;
                num = 0;
            }
        }

        return ans;

    }
};

void solve() {
    Solution a_a;
    std::string s;
    std::cin >> s;
    auto ans = a_a.minimumPushes(s);

    std::cout << ans;
    std::cout << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}