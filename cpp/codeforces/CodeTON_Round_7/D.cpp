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


const int N = 5e5 + 10;
int n;
int tr[N];

int lowbit(int x) {
    // lowbit返回x二进制最后一个1的位置
    // 树状数组中x + lowbit(x) 是x父节点的位置 
    return x & (-x);
}

void modify(int u, int x) {
    // 修改u以及u的负节点（单点修改）
    for (int i = u; i <= n; i += lowbit(i)) {
        tr[i] += x;
    }
}

int query(int u) {
    int ans = 0;
    // 查询u以及u的子节点
    for (int i = u; i; i -= lowbit(i)) {
        ans += tr[i];
    }
    return ans;
}


void init(int n) {
    for (int i = 0; i <= n; i++) {
        tr[i] = 0;
    }
}

void solve() {
    std::cin >> n;
    init(n);
    int q;
    std::cin >> q;
    std::vector<int> a(n + 1);
    std::set<int> S;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        if (a[i] == 1) {
            S.insert(i);
        }
        modify(i, a[i]);
    }

    while (q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int s;
            std::cin >> s;
            int sum = query(n);
            if (sum < s) {
                std::cout << "NO\n";
                continue;
            }
            if (s % 2 == sum % 2) {
                std::cout << "YES\n";
                continue;
            } else {
                if (!S.size()) {
                    std::cout << "NO\n";
                    continue;
                }
                
                auto z1 = S.begin();
                auto z2 = S.end();
                z2 -- ;
                auto l = *z1, r = *z2;
                int w = std::max(sum - query(l), query(r) - 1);
                if (s <= w) {
                    std::cout << "YES\n";
                    continue;
                }
            }
            std::cout << "NO\n";
        } else {
            int i, s;
            std::cin >> i >> s;
            if (a[i] == s) {
                continue;
            } else {
                if (a[i] == 1) {
                    a[i] = 2;
                    modify(i, 1);
                    S.erase(i);
                } else {
                    a[i] = 1;
                    modify(i, -1);
                    S.insert(i);
                }
            }
        }
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
