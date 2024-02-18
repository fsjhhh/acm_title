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

struct Tire {
    // 小写字母：26， 二进制：2 ... 具体由题
    static const int ALPHABET = 26;
    struct Node {
        int len;
        int cnt; // cnt的定义具体由题，在这是前缀数量
        std::array<int, ALPHABET> next;
        Node() : cnt{}, next{} {}
    };

    std::vector<Node> tr;

    Tire() {
        init();
    }

    void init() {
        tr.assign(2, Node());
        tr[0].len = -1;
        tr[0].next.fill(1);
    }

    int newNode() {
        tr.emplace_back();
        return tr.size() - 1;
    }

    int add(const std::vector<int>& a) {
        int p = 1;
        for (auto x : a) {
            if (!tr[p].next[x]) {
                tr[p].next[x] = newNode();
                tr[tr[p].next[x]].len = tr[p].len + 1;
            }
            p = tr[p].next[x];
            tr[p].cnt ++ ;
        }
        return p;
    }

    int add(const std::string& s, char offset = 'a') {
        std::vector<int> a(s.size());
        for (int i = 0; i < (int)s.size(); i++) {
            a[i] = s[i] - offset;
        }
        return add(a);
    }

    int add(const int x) {
        // 如果是int就是31, LL是62
        std::vector<int> a(31);
        for (int i = 30; i >= 0; i--) {
            a[30 - i] = (x >> i & 1);
        }
        return add(a);
    }

    int next(int p, int x) {
        return tr[p].next[x];
    }

    int next(int p, char c, char offset = 'a') {
        return next(p, c - offset);
    }

    int len(int p) {
        return tr[p].len;
    }

    int size() {
        return tr.size();
    }

    // query写下面

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
