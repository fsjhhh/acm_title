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

int borid(int n) {
    int res = 1;
    for(int i = 2; i <= n / i; i ++ ) {
        if(n % i == 0) {
            int s = 0;
            while(n % i == 0) {
                n /= i;
                s ++ ;
            }
            res *= i;
        }
    }
    res *= n;
    return res;
}

void solve() {
    // std::map<int, int> mp;
    

    std::vector g(1010, std::vector<int>(1010));
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            g[i][j] = std::__gcd(i, j);
        }
    }

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        // mp[a[i]] ++ ;
    }

    LL res = 0;
    // std::sort(a.begin(), a.end());

    // auto Lcm = [&](int x, int y) -> LL {
    //     return x * y / std::__gcd(x, y);
    // };

    LL ans = 0;
    // for (int i = 0; i < n; i++) {
    //     mp[a[i]] -- ;
    //     for (int j = i + 1; j < n; j++) {
    //         mp[a[j]] -- ;
    //         LL gcd = std::__gcd(a[i], a[j]);
    //         LL lcm = a[i] * a[j] / gcd;
    //         
    //         auto check = [&](int w) -> bool {
    //             LL k = lcm / w;
    //             if (k < a[j]) {
    //                 return false;
    //             }
    //             if (Lcm(a[i], a[j]) == Lcm(a[i], k) && Lcm(a[i], k) == Lcm(a[j], k)) {
    //                 return true;
    //             } else {
    //                 return false;
    //             }
    //         };
    //
    //         
    //         for (int k = 1; k * k <= gcd; k++) {
    //             if (gcd % k == 0) {
    //                 if (check(gcd / k)) {
    //                     ans += mp[lcm / (gcd / k)];
    //                 }
    //                 if (check(k) && k != gcd / k) {
    //                     ans += mp[lcm / k];
    //                 }
    //             }
    //         }
    //
    //     }
    //     for (int j = i + 1; j < n; j++) {
    //         mp[a[j]] ++ ;
    //     }
    // }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] * g[a[j]][a[k]] == a[j] * g[a[i]][a[k]] && a[k] * g[a[i]][a[j]] == a[j] * g[a[i]][a[k]]) {
                    ans ++ ;
                }
            }
        }
    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}


/*

81
871 508 307 770 401 233 941 313 321 711 361 985 287 969 426 5 711 209 486 961 837 636 811 966 859 747 538 51 451 479 921 561 399 753 252 167 583 431 57 897 781 495 172 888 345 325 899 425 990 826 701 828 217 889 975 525 305 371 901 147 989 981 573 64 801 713 751 743 963 254 681 401 32 69 552 75 377 499 781 496 761

*/
