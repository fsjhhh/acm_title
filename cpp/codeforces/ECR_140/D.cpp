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
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int _0 = -1, _1 = -1;
    int l = 1, r = pow(2, n);
    for (int i = 0; i < s.size(); i ++ ) {
        if (s[i] == '0') {
            _0 ++ ;
            r -= pow(2, _0);
        }
        else {
            _1 ++ ;
            l += pow(2, _1);
        }
    }
    
    for (int i = l; i <= r; i ++ ) {
        std::cout << i << " ";
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