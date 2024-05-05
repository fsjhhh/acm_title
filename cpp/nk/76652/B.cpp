#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <valarray>
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
// #include <bits/stdc++.h>
// priority_queue 优先队列
// std::cout.flush(); 交互题
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
struct node {
    char c;
    int x, y;

    bool operator<(const node a) const {
        if (c == a.c) {
            if (x == a.x) {
                return y < a.y;
            }
            return x < a.x;
        }
        return c > a.c;
    }

};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> mp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mp[i];
    }

    std::string s = "";
    s += mp[0][0];

    std::queue<PII> q;
    q.push({0, 0});

    std::vector<int> dx = {1, 0}, dy = {0, 1};

    std::vector st(n, std::vector<bool>(m, 0));
    st[0][0] = true;
    
    while (1) {
        if (!q.size()) {
            break;
        }

        int si = q.size();

        std::priority_queue<node> pq;
        for (int i = 0; i < si; i++) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 2; i++) {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                    continue;
                }
                
                if (!st[tx][ty]) {
                    pq.push({mp[tx][ty], tx, ty});
                    st[tx][ty] = true;
                }

            }

        }

        if (!pq.size()) {
            break;
        }

        node z = pq.top();
        s += z.c;
        while (pq.size() && pq.top().c == z.c) {
            int x = pq.top().x, y = pq.top().y;
            // std::cout << x << " " << y << "\n";
            q.push({x, y});
            pq.pop();
        }
    }


    std::cout << s << '\n';


}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
