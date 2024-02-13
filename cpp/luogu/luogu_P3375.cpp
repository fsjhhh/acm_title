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

struct KMP {
    std::string S, T;
    int s_len, t_len;
    std::vector<int> ne;
    std::vector<int> pos;
    
    KMP() {}
    KMP(std::string& s, std::string& t) {
        init(s, t);
    }

    void init(std::string& s, std::string& t) {
        S = s;
        T = t;
        s_len = S.size();
        t_len = T.size();
        ne.resize(t_len, 0);
        pos.clear();
    }

    void get_next() {
        ne[0] = 0;
        for (int i = 1, j = 0; i < t_len; i++) {
            while (j && T[j] != T[i]) {
                j = ne[j - 1];
            }
            if (!j && T[j] != T[i]) {
                continue;
            }
            j ++ ;
            ne[i] = j;
        }
    }

    void get_pos() {
        get_next();
        for (int i = 0, j = 0; i < S.size(); i++) {
            while (j && S[i] != T[j]) {
                j = ne[j - 1];
            }
            if (!j && S[i] != T[j]) {
                continue;
            }
            j ++ ;
            if (j == t_len) {
                pos.push_back(i - j + 1);
                j = ne[j - 1];
            }
        }
    }

};

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    KMP kmp(s, t);

    kmp.get_pos();

    for (auto it : kmp.pos) {
        std::cout << it + 1 << "\n";
    }

    for (int i = 0; i < kmp.t_len; i++) {
        std::cout << kmp.ne[i] << " \n"[i == kmp.t_len - 1];
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
