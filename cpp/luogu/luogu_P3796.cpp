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

struct AhoCorasick {
    static const int ALPHABET = 26;
    struct Node {
        int len;
        int fail;
        std::array<int, ALPHABET> next;
        Node() : fail{}, next{} {}
    };
    
    std::vector<Node> tr;
    
    AhoCorasick() {
        init();
    }
    
    void init() {
        tr.assign(2, Node());
        tr[0].next.fill(1);
        tr[0].len = -1;
    }
    
    int newNode() {
        tr.emplace_back();
        return tr.size() - 1;
    }
    
    int add(const std::vector<int> &a) {
        int p = 1;
        for (auto x : a) {
            if (tr[p].next[x] == 0) {
                tr[p].next[x] = newNode();
                tr[tr[p].next[x]].len = tr[p].len + 1;
            }
            p = tr[p].next[x];
        }
        return p;
    }
    
    int add(const std::string &s, char offset = 'a') {
        std::vector<int> b(s.size());
        for (int i = 0; i < (int)s.size(); i++) {
            b[i] = s[i] - offset;
        }
        return add(b);
    }
    
    std::vector<int> build() {
        std::vector<int> res(tr.size());
        std::queue<int> q;
        q.push(1);
        
        while (q.size()) {
            int x = q.front();
            q.pop();
            
            for (int i = 0; i < ALPHABET; i++) {
                if (tr[x].next[i] == 0) {
                    tr[x].next[i] = tr[tr[x].fail].next[i];
                } else {
                    tr[tr[x].next[i]].fail = tr[tr[x].fail].next[i];
                    res[tr[tr[x].next[i]].fail] ++ ;
                    q.push(tr[x].next[i]);
                }
            }
        }

        return res;
    }
    
    int next(int p, int x) {
        return tr[p].next[x];
    }
    
    int next(int p, char c, char offset = 'a') {
        return next(p, c - 'a');
    }
    
    int link(int p) {
        return tr[p].fail;
    }
    
    int len(int p) {
        return tr[p].len;
    }
    
    int size() {
        return tr.size();
    }
};

void solve(int n) {
    AhoCorasick ac;
    std::vector<int> flag, ma(n);
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        int u = ac.add(a[i]);
        flag.resize(ac.size(), -1);
        if (flag[u] == -1) {
            flag[u] = i;
        }
        ma[i] = flag[u];
    }

    auto in = ac.build();

    std::string s;
    std::cin >> s;
    std::vector<int> z(ac.size());
    int p = 1, m = s.size();
    for (int i = 0; i < m; i++) {
        p = ac.tr[p].next[s[i] - 'a'];
        z[p] ++ ;
    }
    
    std::queue<int> q;
    for (int i = 1; i < ac.size(); i++) {
        if (!in[i]) {
            q.push(i);
        }
    }
    
    std::vector<int> ans(n + 1);
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (flag[u] != -1) {
            ans[flag[u]] = z[u];
        }
        int v = ac.tr[u].fail;
        in[v] -- ;
        z[v] += z[u];
        if (!in[v]) {
            q.push(v);
        }
    }

    int mx = 0;
    std::vector<int> idx;
    for (int i = 0; i < n; i++) {
        if (mx < ans[ma[i]]) {
            mx = ans[ma[i]];
            idx.clear();
            idx.push_back(i);
        } else if (mx == ans[ma[i]]) {
            idx.push_back(i);
        }
    }

    std::cout << mx << "\n";
    for (int i : idx) {
        std::cout << a[i] << "\n";
    }

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t) {
        int x;
        std::cin >> x;
        if (!x) {
            break;
        }
        solve(x);
    }
    return 0;
}


