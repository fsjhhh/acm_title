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

#define int long long

const int N = 1e6 + 10;
int h[N], si = 0;
int ph[N], hp[N];

void heap_swap(int u, int v)
{
    std::swap(h[u], h[v]);
    std::swap(hp[u], hp[v]);
    std::swap(ph[hp[u]], ph[hp[v]]);
}

void down(int u)
{
    int t = u;
    if(2 * u <= si && h[t] > h[2 * u]) t = 2 * u;
    if(2 * u + 1 <= si && h[t] > h[2 * u + 1]) t = 2 * u + 1;
    if(t != u)
    {
        heap_swap(t, u);
        down(t);
    }
}

void add(int u, int x) {
    h[u] += x;
    if (2 * u <= si) {
        add(2 * u, x);
    }
    if (2 * u + 1 <= si) {
        add(2 * u + 1, x);
    }
}

void up(int u)
{
    if(u / 2 > 0 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        up(u / 2);
    }
}
void solve() {
    int q, s = 0;
    std::cin >> q;
    int m = 0;
    while (q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x;
            std::cin >> x;
            m ++ ;
            h[++ si] = x;
            ph[m] = si;
            hp[si] = m;
            up(si);
        } else if (op == 2) {
            std::cout << h[1] << "\n";
            heap_swap(1, si);
            si -- ;
            down(1);
        } else {
            int x;
            std::cin >> x;
            add(1, x);
        }

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
