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

struct Node {
    int x, y, z;
};

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].x >> a[i].y >> a[i].z;
    }
    
    std::vector mp(4, std::vector<int>(4, -1));
    
    auto check = [&](Node w) -> bool {
        int z;
        if (w.x == 1 && w.y == 2) {
            z = 3;
        }
        if (w.x == 2 && w.y == 1) {
            z = 3;
        }
        if (w.x == 1 && w.y == 3) {
            z = 2;
        }
        if (w.x == 3 && w.y == 1) {
            z = 2;
        }
        if (w.x == 2 && w.y == 3) {
            z = 1;
        }
        if (w.x == 3 && w.y == 2) {
            z = 1;
        }

        if (mp[w.x][z] == -1 || mp[w.y][z] == -1) {
            return true;
        }

        if (w.z == 0) {
            if (mp[w.x][z] == 4 && mp[w.y][z] == 3) {
                return false;
            }
            if (mp[w.x][z] == 2 && mp[w.y][z] == 3) {
                return false;
            }
            if (mp[w.x][z] == 4 && mp[w.y][z] == 1) {
                return false;
            }
            if (mp[w.x][z] == 0 && mp[w.y][z] == 3) {
                return false;
            }
            if (mp[w.x][z] == 4 && mp[w.y][z] == 0) {
                return false;
            }
        } else {
            if (mp[w.x][z] == 1 && mp[w.y][z] == 2) {
                return false;
            }
            if (mp[w.x][z] == 1 && mp[w.y][z] == 4) {
                return false;
            }
            if (mp[w.x][z] == 3 && mp[w.y][z] == 2) {
                return false;
            }
            if (mp[w.x][z] == 3 && mp[w.y][z] == 4) {
                return false;
            }
            if (mp[w.x][z] == 1 && mp[w.y][z] == 0) {
                return false;
            }
            if (mp[w.x][z] == 3 && mp[w.y][z] == 0) {
                return false;
            }
            if (mp[w.x][z] == 0 && mp[w.y][z] == 2) {
                return false;
            }
            if (mp[w.x][z] == 0 && mp[w.y][z] == 4) {
                return false;
            }
            if (mp[w.x][z] == 0 && mp[w.y][z] == 0) {
                return false;
            }
        }

        return true;

    };

    for (int i = 0; i < n; i++) {
        if (a[i].x == a[i].y) {
            if (a[i].z == 1) {
                std::cout << "No\n";
                return ;
            } else {
                continue;
            }
        }

        if (!check(a[i])) {
            std::cout << "No\n";
            return ;
        }

        if (a[i].z == 0) {
            if (mp[a[i].x][a[i].y] == -1) {
                mp[a[i].x][a[i].y] = 1;
                mp[a[i].y][a[i].x] = 2;
            } else if (mp[a[i].x][a[i].y] == 2) {
                mp[a[i].x][a[i].y] = 0;
                mp[a[i].y][a[i].x] = 0;
            } else if (mp[a[i].x][a[i].y] == 4) {
                std::cout << "No\n";
                return ;
            }
        } else {
            if (mp[a[i].x][a[i].y] == -1) {
                mp[a[i].x][a[i].y] = 4;
                mp[a[i].y][a[i].x] = 3;
            } else if (mp[a[i].x][a[i].y] == 2) {
                mp[a[i].x][a[i].y] = 4;
                mp[a[i].y][a[i].x] = 3;
            } else if (mp[a[i].x][a[i].y] == 0 || mp[a[i].x][a[i].y] == 1 || mp[a[i].x][a[i].y] == 3) {
                std::cout << "No\n";
                return ;
            }
        }
    }

    std::cout << "Yes\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

