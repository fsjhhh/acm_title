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

const int N = 2e5 + 10;
int a[N];

void solve()
{
    int n, x;
    std::cin >> n >> x;
    std::set<int> s;
    for (int i = 1; i <= n; i ++ ) {
        std::cin >> a[i];
        s.insert(a[i]);
    }

    for (int i = 1; i <= n; i ++ ) {
        if (s.find(a[i] - x) != s.end()) {
            std::cout << "Yes" << "\n";
            return ;
        }
        if (s.find(a[i] + x) != s.end()) {
            std::cout << "Yes" << "\n";
            return ;
        }
    }
    std::cout << "No" << "\n";

}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}