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
    static const int ALPHABET = 62;
    struct Node {
        int len;
        int cnt;
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

    int add(const std::string& s, char offset_1 = 'a', char offset_2 = 'A', char offset_3 = '0') {
        std::vector<int> a(s.size());
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                a[i] = s[i] - offset_1;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                a[i] = s[i] - offset_2 + 26;
            } else {
                a[i] = s[i] - offset_3 + 52;
            }
        }
        return add(a);
    }

    int next(int p, int x) {
        return tr[p].next[x];
    }

    int next(int p, char c, char offset_1 = 'a', char offset_2 = 'A', char offset_3 = '0') {
        if (c >= 'a' && c <= 'z') {
            return next(p, c - offset_1);
        } else if (c >= 'A' && c <= 'Z') {
            return next(p, c - offset_2 + 26);
        } else {
            return next(p, c - offset_3 + 52);
        }
    }

    int len(int p) {
        return tr[p].len;
    }

    int size() {
        return tr.size();
    }


    int query(const std::vector<int>& a) {
        int p = 1;
        for (auto x : a) {
            if (!tr[p].next[x]) {
                return 0;
            }
            p = tr[p].next[x];
        }

        return tr[p].cnt;

    }

    int query(const std::string& s, char offset_1 = 'a', char offset_2 = 'A', char offset_3 = '0') {
        std::vector<int> a(s.size());
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                a[i] = s[i] - offset_1;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                a[i] = s[i] - offset_2 + 26;
            } else {
                a[i] = s[i] - offset_3 + 52;
            }
        }
        return query(a);
    }

};

void solve() {
    int n, q;
    std::cin >> n >> q;

    Tire tire;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        tire.add(s);
    }

    while (q -- ) {
        std::string t;
        std::cin >> t;

        std::cout << tire.query(t) << "\n";
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
