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

#define int long long

typedef long long LL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 4e5 + 10;
int tree[2][N], idx;

void insert(int x) {
    int p = 0;
    for (int i = 20; i >= 0; i--) {
        int u = (x >> i) & 1;
        if (!tree[u][p]) {
            tree[u][p] = ++ idx;
        }
        p = tree[u][p];
    }
}

bool query(int x, int n) {
    int p = 0, maxx = 0;
    for (int i = 20; i >= 0; i--) {
        int u = (x >> i) & 1;
        if (tree[!u][p]) {
            maxx |= (1 << i);
            p = tree[!u][p];
        } else if (tree[u][p]) {
            p = tree[u][p];
        } else {
            return false;
        }

        if (maxx >= n) {
            return false;
        }
    }

    return (maxx == (n - 1));
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    int x = 0;
    for (int i = 1; i < n; i++) {
        std::cin >> a[i];
        x ^= a[i];
        insert(x);
    }

    b[0] = n - 1;
    for (int i = 0; i < n; i++) {
        if (query(i, n)) {
            b[0] = i;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        b[i] = b[i - 1] ^ a[i];
    }

    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " \n"[i == n - 1];
    }

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
