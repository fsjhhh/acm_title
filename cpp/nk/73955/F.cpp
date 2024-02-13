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
    std::string a, b;
    std::cin >> a >> b;
    int ans = 6;
    std::set<std::string> s = {a};
    std::queue<std::string> q;
    q.push(a);
    auto z = [&](char &x) -> void {
        x = (char)(((int)(x - '0') ^ 1) + '0');
    };

    auto dfs = [&](auto self, int cnt, std::string x) -> void {
        if (cnt == 6) {
            std::string it = a;
            int sum = 0;
            for (int i = 0; i < cnt; i++) {
                if (x[i] == '1') {
                    if (i == 0) {
                        z(it[0]);
                        z(it[1]);
                        z(it[4]);
                        z(it[5]);
                    } else if (i == 1) {
                        z(it[0]);
                        z(it[1]);
                        z(it[2]);
                    } else if (i == 2) {
                        z(it[1]);
                        z(it[2]);
                        z(it[3]);
                        z(it[5]);
                    } else if (i == 3) {
                        z(it[2]);
                        z(it[3]);
                        z(it[4]);
                        z(it[5]);
                    } else if (i == 4) {
                        z(it[0]);
                        z(it[3]);
                        z(it[4]);
                    } else {
                        z(it[0]);
                        z(it[2]);
                        z(it[3]);
                        z(it[5]);
                    }
                    sum ++ ;
                }
            }
            if (it == b) {
                ans = std::min(ans, sum);
            }
            return ;
        }
        for (int i = 0; i < 2; i++) {
            x += ('0' + i);
            self(self, cnt + 1, x);
            x.pop_back();
        }
    };

    dfs(dfs, 0, "");

    if (ans == 6) {
        std::cout << "-1\n";
    } else {
        std::cout << ans << "\n";
    }

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
