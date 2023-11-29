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
#include <iomanip> // std::fixed std::setprecision(x) 保留x位小数
#include <array>
#include <bitset>
#include <functional>
#include <ranges>
//#include <bits/stdc++.h>
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

const int N = 1010;
LL n, m, k, q;
LL g[N][N];
LL s[N][N];
LL s1[N][N];

void solve() {
    LL l;
    std::cin >> n >> k >> l;
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            g[i][j] = 1;
        }
    }
    for (int u = 1; u <= n; u++)
    {
        LL x, y;
        std::cin >> x >> y;
        s[x][y]+=-1;
        s[x+k][y]-=-1;
        s[x][y+k]-=-1;
        s[x+k][y+k]+=-1;
    }
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
            if(s[i][j]!=0)
            {
                g[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= l; j++) {
            s1[i][j] = s1[i][j - 1] + s1[i - 1][j] - s1[i - 1][j - 1] + g[i][j]; // 求前缀和
        }
    
    std::cin >> q;
    while (q--)
    {
        LL x, y;
        std::cin >> x >> y;
        std::cout << s1[x + k - 1][y + k - 1] - s1[x + k - 1][y - 1] - s1[x - 1][y + k - 1] + s1[x - 1][y - 1] << "\n";
    }
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
