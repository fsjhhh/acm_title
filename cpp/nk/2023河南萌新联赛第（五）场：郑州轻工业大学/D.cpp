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
 	s = "2" + s;
    std::string s_1 = s, s_2 = s;
    for (int i = 1; i < s.size(); i ++ ) {
        if (s[i] == '?') {
            s_1[i] = '1';
            s_2[i] = '0';
        }
    }

    int ans = 0, cnt_1 = 0, cnt_2 = 0;
    for (int i = 1; i < s.size(); i ++ ) {
        if (s_1[i] == s_1[i - 1]) {
            cnt_1 ++ ;
            ans = std::max(ans, cnt_1);
        }
        else {
            cnt_1 = 0;
        }
        if (s_2[i] == s_2[i - 1]) {
            cnt_2 ++ ;
            ans = std::max(ans, cnt_2);
        }
        else {
            cnt_2 = 0;
        }
    }

 	std::cout << ans + 1 << "\n";
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