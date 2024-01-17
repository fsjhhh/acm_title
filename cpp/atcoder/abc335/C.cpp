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

void solve() {
    int n;
    std::cin >> n;
    std::deque<PII> q;
    for (int i = 1; i <= n; i++) {
        q.push_back({i, 0});
    }
    
    int Q;
    std::cin >> Q;
    while (Q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            char c;
            std::cin >> c;
            if (c == 'R') {
                q.pop_back();
                auto z = q.front();
                z.first ++ ;
                q.push_front(z);
            } else if (c == 'L') {
                q.pop_back();
                auto z = q.front();
                z.first -- ;
                q.push_front(z);
            } else if (c == 'U') {
                q.pop_back();
                auto z = q.front();
                z.second ++ ;
                q.push_front(z);
            } else {
                q.pop_back();
                auto z = q.front();
                z.second -- ;
                q.push_front(z);
            }
        } else {
            int x;
            std::cin >> x;
            x -- ;
            std::cout << q[x].first << " " << q[x].second << "\n";
        }

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
