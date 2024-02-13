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

const int N = 5e5 + 10;
int lchild[N], rchild[N], num[N];

void solve() {
    int a, b;
    std::cin >> a >> b;
    int n = a + b;
    for (int i = 1; i <= n; i++) {
        lchild[i] = rchild[i] = -1;
    }

    a -- ;

    num[0] = num[1] = 0;
    int w = 1;

    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            if (b >= 2) {
                int l = w + 1, r = w + 2;
                if (l <= i) {
                    continue;
                }
                num[l] = num[r] = 1;
                lchild[i] = l;
                rchild[i] = r;
                b -= 2;
                w += 2;
            }
        } else if (num[i] == 1) {
            if (a >= 2) {
                int l = w + 1, r = w + 2;
                if (l <= i) {
                    continue;
                }
                num[l] = num[r] = 0;
                lchild[i] = l;
                rchild[i] = r;
                a -= 2;
                w += 2;
            }
        }
    }

    if (a || b) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
            std::cout << lchild[i] << " " << rchild[i] << "\n";
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
