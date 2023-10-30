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

void solve(int t) {
    double x, b;
    scanf("%lf%lf", &x, &b);
    double ans = (std::pow(x, b) - std::pow(x - 1, b)) * (x + 1) * x / (std::pow(x, b) * 2);
    printf("Case #%d: %.3lf\n", t, ans);
}

int main() {
    IOS;
    int t = 1, z = 0;
    scanf("%d", &t);
    while (t -- ) {
    	z ++ ;
        solve(z);
    }
    return 0;
}