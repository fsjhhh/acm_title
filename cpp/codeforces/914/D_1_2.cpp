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

const int N = 2e5 + 10;
struct TREE {
    struct Node {
        int l, r;
        int minn, maxx;
    };
    std::vector<Node> tr;

    TREE (int n, std::vector<int>& a) {
        tr.resize(n * 4 + 10);
        build(1, 1, n, a);
    }
    
    void push_up(int u) {
        tr[u].maxx = std::max(tr[u << 1].maxx, tr[u << 1 | 1].maxx);
        tr[u].minn = std::min(tr[u << 1].minn, tr[u << 1 | 1].minn);
    }

    void build(int u, int l, int r, std::vector<int>& a) {
        if (l == r) {
            tr[u].l = tr[u].r = l;
            tr[u].maxx = tr[u].minn = a[l];
            return ;
        }
        int mid = (l + r) >> 1;
        tr[u].l = l;
        tr[u].r = r;
        build(u << 1, l, mid, a);
        build(u << 1 | 1, mid + 1, r, a);
        push_up(u);
    }

    int query_min(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].minn;
        }
        int mid = (tr[u].l + tr[u].r) >> 1, ans = INF;
        if (l <= mid) {
            ans = std::min(ans, query_min(u << 1, l, r));
        }
        if (r > mid) {
            ans = std::min(ans, query_min(u << 1 | 1, l, r));
        }
        push_up(u);
        return ans;
    }

    int query_max(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].maxx;
        }
        int mid = (tr[u].l + tr[u].r) >> 1, ans = 0;
        if (l <= mid) {
            ans = std::max(ans, query_max(u << 1, l, r));
        }
        if (r > mid) {
            ans = std::max(ans, query_max(u << 1 | 1, l, r));
        }
        return ans;
    }

};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }

    std::vector<PII> c;
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            std::cout << "NO\n";
            return ;
        } else if (a[i] < b[i]) {
            c.push_back({i, b[i]});
        }
    }

    TREE tr_a(n, a), tr_b(n, b);

    for (auto [x, y]: c) {
        bool pd = false;
        int l = x + 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (tr_a.query_max(1, x, mid) == y) {
                if (tr_b.query_min(1, x, mid) >= y) {
                    pd = true;
                    break;
                } else {
                    r = mid - 1;
                }
            } else if (tr_a.query_max(1, x, mid) > y) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        l = 1, r = x - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (tr_a.query_max(1, mid, x) == y) {
                if (tr_b.query_min(1, mid, x) >= y) {
                    pd = true;
                    break;
                } else {
                    l = mid + 1;
                }
            } else if (tr_a.query_max(1, mid, x) > y) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (!pd) {
            std::cout << "NO\n";
            return ;
        }
    }
    std::cout << "YES\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
