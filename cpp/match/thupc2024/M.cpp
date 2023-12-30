#include <bits/stdc++.h>
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

char a[210];
std::string z;

void solve() {
    std::cin.getline(a, 209);
    std::string s = "You are right, but ";
    for (int i = 0; i < 19; i++) {
        if (a[i] != s[i]) {
            std::cout << "Human\n";
            return ;
        }
    }
    std::cout << "AI\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
