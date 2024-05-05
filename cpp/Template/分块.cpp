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

struct Block {
    int sq;
    std::vector<int> st, ed, bel, siz;
    
    Block() {}
    Block(int n) {
        init(n);
    }

    void init(int n) {
        sq = sqrt(n);
        st.resize(sq);
        ed.resize(sq);
        bel.resize(n);
        siz.resize(sq);
        
        init_block(n);
    }

    void init_block(int n) {
        for (int i = 0; i < sq; i++) {
            st[i] = n / sq * i;
            ed[i] = n / sq * (i + 1) - 1;
        }
        ed[sq - 1] = n - 1;

        for (int i = 0; i < sq; i++) {
            for (int j = st[i]; j <= ed[i]; j++) {
                bel[j] = i;
            }
        }

        for (int i = 0; i < sq; i++) {
            siz[i] = ed[i] - st[i] + 1;
        }
    }

};

void solve() {
    
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
