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
    int m, n;
    std::cin >> m >> n;
    if (m == 0) {
        std::cout << "Alice" << "\n";
        return ;
    }
    else {
        if (n == 0) {
            if (m % 3 == 0) {
                std::cout << "Bob" << "\n";
                return ;
            }
            else {
                std::cout << "Alice" << "\n";
                return ;
            }
        }
        else {
            if (m % 3 == 0) {
                std::cout << "Alice" << "\n";
                return ;
            }
            else if (m % 3 == 1) {
                if (n > 1) {
                    std::cout << "Alice" << "\n";
                    return ;
                } 
                else {
                    std::cout << "Bob" << "\n";
                    return ;
                }
            }
            else {
                if (n == 2) {
                    std::cout << "Bob" << "\n";
                    return ;
                }
                else {
                    std::cout << "Alice" << "\n";
                    return ;
                }
            }
        }
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