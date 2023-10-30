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
 	std::string x1, x2;
    int p1, p2;
    std::cin >> x1 >> p1 >> x2 >> p2;
    if (x1.size() + p1 == x2.size() + p2) {
        while (x1.size() < x2.size()) {
            x1 += "0";
        }
        while (x1.size() > x2.size()) {
            x2 += "0";
        }
        for (int i = 0; i < x1.size(); i ++ ) {
            if (x1[i] > x2[i]) {
                std::cout << ">" << "\n";
                return ;
            }
            if (x1[i] < x2[i]) {
                std::cout << "<" << "\n";
                return ;
            }
        }
        std::cout << "=" << "\n";
    }
    else if (x1.size() + p1 < x2.size() + p2) {
        std::cout << "<" << "\n";
    }
    else {
        std::cout << ">" << "\n";
    }
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