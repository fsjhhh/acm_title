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
    std::string s;
    std::cin >> s;
    std::set<std::string> se;
    se.insert("ACE");
    se.insert("BDF");
    se.insert("CEG");
    se.insert("DFA");
    se.insert("EGB");
    se.insert("FAC");
    se.insert("GBD");
    if (se.find(s) != se.end()) {
        std::cout << "Yes" << "\n";
    }
    else {
        std::cout << "No" << "\n";
    }
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}