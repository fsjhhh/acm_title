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

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;
    int q;
    std::cin >> q;
    std::vector<std::pair<int, char>> v;
    int pd = 0;
    while (q -- ) {
        int op, x;
        char c;
        std::cin >> op >> x >> c;
        if (op == 1) {
            v.push_back({x, c});
        }
        if (op == 2) {
            pd = 2;
            for (auto it : v) {
                s[it.first - 1] = it.second;
            }
            v.clear();
        }
        if (op == 3) {
            pd = 3;
            for (auto it : v) {
                s[it.first - 1] = it.second;
            }
            v.clear();
        }
    }
    if (pd == 2) {
        for (int i = 0; i < s.size(); i ++ ) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            }    
        }
    }
    if (pd == 3) {
        for (int i = 0; i < s.size(); i ++ ) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = s[i] - 'a' + 'A';
            }    
        }
    }
    for (auto it : v) {
        s[it.first - 1] = it.second;
    }
    std::cout << s << "\n";
}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
