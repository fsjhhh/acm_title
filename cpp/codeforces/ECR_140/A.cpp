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
    std::vector<PII> v(4);
    for (int i = 1; i <= 3; i ++ )
        std::cin >> v[i].first >> v[i].second;
    for (int i = 1; i <= 3; i ++ ) {
        if (i == 1) {
            if ((v[i].first < v[2].first && v[i].first > v[3].first) || (v[i].first > v[2].first && v[i].first < v[3].first)) {
                std::cout << "Yes" << "\n";
                return ;
            }
            if ((v[i].second < v[2].second && v[i].second > v[3].second) || (v[i].second > v[2].second && v[i].second < v[3].second)) {
                std::cout << "Yes" << "\n";
                return ;
            }
        }
        if (i == 2) {
            if ((v[i].first < v[1].first && v[i].first > v[3].first) || (v[i].first > v[1].first && v[i].first < v[3].first)) {
                std::cout << "Yes" << "\n";
                return ;
            }
            if ((v[i].second < v[1].second && v[i].second > v[3].second) || (v[i].second > v[1].second && v[i].second < v[3].second)) {
                std::cout << "Yes" << "\n";
                return ;
            }
        }
        if (i == 3) {
            if ((v[i].first < v[2].first && v[i].first > v[1].first) || (v[i].first > v[2].first && v[i].first < v[1].first)) {
                std::cout << "Yes" << "\n";
                return ;
            }
            if ((v[i].second < v[2].second && v[i].second > v[1].second) || (v[i].second > v[2].second && v[i].second < v[1].second)) {
                std::cout << "Yes" << "\n";
                return ;
            }
        }
    }
    std::cout << "No" << "\n";
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