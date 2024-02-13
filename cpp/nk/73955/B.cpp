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

const int mod = 1e9 + 7;

class Matrix {
public:
    std::vector<std::vector<int>> Matr;
    Matrix (int n, int m) {
        Matr.resize(n);
        for (int i = 0; i < n; i++) {
            Matr[i].resize(m);
            for (int j = 0; j < m; j++) {
                Matr[i][j] = 1;
            }
        }
    }

    Matrix operator*(Matrix a) {
        int n = (int)Matr.size(), m = (int)a.Matr[0].size(), t = (int)Matr[0].size();
        Matrix res(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res.Matr[i][j] = 0;
                for (int k = 0; k < t; k++) {
                    res.Matr[i][j] = (res.Matr[i][j] + Matr[i][k] * a.Matr[k][j] % mod) % mod;
                }
            }
        }
        return res;
    }

    void Matrix_Power(int b, Matrix &res) {
        int n = (int)Matr.size();
        Matrix a = *this;
        while (b) {
            if (b & 1) {
                res = res * a;
            }
            b >>= 1;
            a = a * a;
        }
        
    }

};

void solve() {
    int n;
    std::cin >> n;
    Matrix a(1, 2), b(2, 2), c(2, 2);
    a.Matr[0][0] = 3, a.Matr[0][1] = 2;
    if (n == 0) {
        std::cout << 1 << "\n";
        return ;
    }
    if (n == 1) {
        std::cout << "2\n";
        return ;
    }
    if (n == 2) {
        std::cout << "3\n";
        return;
    }
    b.Matr[1][1] = c.Matr[1][1] = 0;
    b.Matrix_Power(n - 3, c);
    Matrix res = a * c;
    std::cout << (res.Matr[0][0] % mod) << "\n";
}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

