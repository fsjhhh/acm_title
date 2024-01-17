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

struct node {
    int w;
    int l, r;

    bool operator<(const node a) const {
        if (this -> w == a.w) {
            return this -> l > a.l;
        }
        return this -> w > a.w;
    }

};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::priority_queue<node> q;
    for (int i = 0; i < n; i++) {
        q.push({a[i], i, i + 1});
    }

    
    // while (q.size()) {
    //     std::cout << q.top().w << " " << q.top().l << " " << q.top().r << "\n";
    //     q.pop();
    // }

    while (q.size() > 1) {
        auto a = q.top();
        q.pop();
        auto b = q.top();
        q.pop();
        if (!q.size()) {
            if (a.w != b.w) {
                std::cout << "No\n";
                return ;
            }
            if (a.r == b.l) {
                std::cout << "Yes\n";
                return ;
            } else {
                std::cout << "No\n";
            }
        }
        auto c = q.top();
        q.pop();
        if (a.w != b.w) {
            std::cout << "No\n";
            return ;
        }
        if (b.w != c.w) {
            q.push(c);
            if (a.r == b.l) {
                q.push({a.w + 1, a.l, b.r});
            } else {
                std::cout << "No\n";
                return ;
            }
            continue;
        }

        if (c.w == q.top().w && c.r == q.top().l) {
            q.push(c);
            if (a.r == b.l) {
                q.push({a.w + 1, a.l, b.r});
            } else {
                std::cout << "No\n";
                return ;
            }
            continue;
        }

        if (a.r == b.l && b.r == c.l) {
            q.push({a.w + 1, a.l, c.r});
        } else {
            std::cout << "No\n";
            return ;
        }

    }

    std::cout << "Yes\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
