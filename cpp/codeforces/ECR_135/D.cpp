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

const int N = 2010;
int f[N][N];

void solve() 
{
    memset(f, 0, sizeof f);
    std::string s;
    std::cin >> s;
    int n = s.size();
    for (int len = 2; len <= n; len += 2) {
        for (int i = 0; i < n; i ++ ) {
            int j = i + len - 1;
            if (j >= n) {
                break;
            }
            if (len == 2) {
                f[i][j] = (s[i] != s[j]);
                continue;
            }
            if ((f[i + 1][j - 1] || s[i] < s[j]) && (f[i + 2][j] || s[i] < s[i + 1])) {
                f[i][j] = 1;
            }
            if ((f[i + 1][j - 1] || s[j] < s[i]) && (f[i][j - 2] || s[j] < s[j - 1])) {
                f[i][j] = 1;
            }
        }
    }

    if (f[0][n - 1]) {
        std::cout << "Alice" << "\n";
    }
    else {
        std::cout << "Draw" << "\n";
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