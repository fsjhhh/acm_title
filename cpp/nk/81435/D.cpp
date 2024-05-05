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

void solve() {
    int n, b, ra, rb;
    std::cin >> n >> b >> ra >> rb;

    std::vector<LL> a(n + 1);
    int idx = 1;
    std::priority_queue<LL, std::vector<LL>, std::greater<LL>> que;
    std::priority_queue<PLL> pq;
    std::set<PLL> s;
    LL R = 0, T = 0;
    LL ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        std::cin >> a[i];
        que.push(a[i]);
        T += a[i];
        while (que.size() > b) {
            T -= que.top();
            que.pop();
        }

        s.insert({a[i], i});
        R += a[i];
        while (s.size() > rb) {
            auto it = s.begin();
            R -= (*it).first;
            pq.push(*it);
            s.erase(it);
        }

        if (i - ra > 0) {
            auto it = s.find({a[i - ra], i - ra});
            if (it != s.end()) {
                R -= (*it).first;
                s.erase(it);
            }
        }

        while (s.size() < rb) {
            if (!pq.size()) {
                break;
            }
            auto it = pq.top();
            pq.pop();
            if (it.second > i - ra) {
                s.insert(it);
                pq.pop();
                R += it.first;
            }
        }

        ans = std::max(ans, R + T);

    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
