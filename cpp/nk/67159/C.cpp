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

const int N = 1e6 + 10;
int tr[N][26], idx, cnt[N];
std::string str = "lenovo";

void insert(std::string s, int pos) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!tr[p][u]) {
            tr[p][u] = ++ idx;
        }
        p = tr[p][u];
        if (i >= pos) {
            cnt[p] ++ ;
        }
    }
}

int query(std::string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!tr[p][u]) {
            return 0;
        }
        p = tr[p][u];
    }
    return cnt[p];
}

void solve() {
    int n, ans = 0;
    std::cin >> n;

    auto check = [&](std::string s, int x) {
        for (int i = 0; i < 6; i++) {
            if (s[x + i] != str[i]) {
                return false;
            }
        }
        return true;
    };

    while (n -- ) {
        int op;
        std::string s;
        std::cin >> op >> s;
        if (op == 1) {
            int pd = -1;
            for (int i = s.size() - 6; i >= 0; i--) {
                if (check(s, i)) {
                    pd = i;
                    break;
                }
            }
            if (pd != -1) {
                ans ++ ;
                insert(s, pd);
            }
        } else {
            int res = query(s);
            std::cout << ans - res << "\n";
        }
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
