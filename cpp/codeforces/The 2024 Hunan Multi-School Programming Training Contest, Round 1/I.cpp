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
    int n;
    std::cin >> n;
    std::vector<std::set<char>> v(26);
    
    std::string z;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        z = s;

        if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) {
            std::cout << "0\n";
            return ;
        }

        v[s[0] - 'a'].insert(s[1]);
        v[s[0] - 'a'].insert(s[2]);
        v[s[1] - 'a'].insert(s[0]);
        v[s[1] - 'a'].insert(s[2]);
        v[s[2] - 'a'].insert(s[0]);
        v[s[2] - 'a'].insert(s[1]);
    }

    int cnt = 0;

    std::set<int> s;

    for (int i = 0; i < 26; i++) {
        if (v[i].size()) {
            cnt ++ ;
            s.insert(i);
        }
    }

    if (cnt > 18) {
        std::cout << "0\n";
        return ;
    }

    std::string a[3];
    a[0] += z[0], a[1] += z[1], a[2] += z[2];
    s.erase(z[0] - 'a');
    s.erase(z[1] - 'a');
    s.erase(z[2] - 'a');
    cnt -= 3;
    std::vector<int> w(s.begin(), s.end());

    s.insert(z[0] - 'a');
    s.insert(z[1] - 'a');
    s.insert(z[2] - 'a');

    auto dfs = [&](auto self, int id) -> bool {

        if (id == cnt) {
            return true;
        }

        for (int i = 0; i < 3; i++) {
            if (a[i].find(w[id] + 'a') == -1 && a[i].size() < 6) {
                bool ok = false;
                for (auto it : a[i]) {
                    if (v[w[id]].find(it) != v[w[id]].end()) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    continue;
                }
                a[i] += (w[id] + 'a');
                if (self(self, id + 1)) {
                    return true;
                }
                a[i].pop_back();
            }
        }

        return false;

    };

    if (dfs(dfs, 0)) {

        for (int i = 0; i < 26; i++) {
            if (s.find(i) == s.end()) {
                s.insert(i);
                for (int j = 0; j < 3; j++) {
                    if (a[j].size() < 6) {
                        a[j] += (i + 'a');
                        break;
                    }
                }
            }
        }
        std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    } else {
        std::cout << "0\n";
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
