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
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 25;
short a[N], b[N];

void solve()
{
    short n;
    std::cin >> n;
    short num = 0, num_2 = 0, num_3 = 0;
    for (short i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
        if (a[i] == 0) {
            num ++ ;
        }
        if (a[i] <= 0) {
            num_2 ++ ;
        }
        if (a[i] >= 0) {
            num_3 ++ ;
        }
    }

    if (num == n) {
        std::cout << 0 << "\n";
        return ;
    }

    if (num_2 == n) {
        std::cout << n - 1 << "\n";
        for (int i = n - 1; i >= 1; i -- ) {
            std::cout << i << " " << i + 1 << "\n";
        }
        return ;
    }

    if (num_3 == n) {
        std::cout << n - 1 << "\n";
        for (int i = 2; i <= n; i ++ ) {
            std::cout << i << " " << i - 1 << "\n";
        }
        return ;
    }

    for (short i = 1; i <= n; i ++ ) {
        b[i] = a[i];
    }

    std::vector<std::pair<short, short>> v1;
    if (1) {
    	short t = 1, maxx = 0, minn = 0;
    	for (short i = 1; i <= n; i ++ ) {
            if (a[i] < 0 && maxx < abs(a[i])) {
                t = i;
                maxx = abs(a[i]);
            }
            else {
                if (minn < a[i]) {
                    minn = a[i];
                }
            }
        }
    	while (a[t] > minn * -1) {
    		a[t] += a[t];
    		v1.push_back({t, t});
    	}

    	for (short i = 1; i <= n; i ++ ) {
    		if (a[i] > 0) {
    			a[i] += a[t];
    			v1.push_back({i, t});
    		}
    	}

    	for (short i = n - 1; i >= 1; i -- ) {
    		v1.push_back({i, i + 1});
    	}
    }

    for (short i = 1; i <= n; i ++ ) {
        a[i] = b[i];
    }

    std::vector<std::pair<short, short>> v2;
    if (1) {
    	short t = 1, maxx = 0, minn = 0;
    	for (short i = 1; i <= n; i ++ ) {
            if (a[i] > 0 && (a[i] > maxx)) {
                t = i;
                maxx = a[i]; 
            }
            else {
                if (minn < abs(a[i])) {
                    minn = abs(a[i]);
                }
            }
        }
    	while (a[t] < minn) {
    		a[t] += a[t];
    		v2.push_back({t, t});
    	}

    	for (short i = 1; i <= n; i ++ ) {
    		if (a[i] < 0) {
    			a[i] += a[t];
    			v2.push_back({i, t});
    		}
    	}

    	for (short i = 2; i <= n; i ++ ) {
    		v2.push_back({i, i - 1});
    	}
    }

    if (v1.size() < v2.size()) {
        std::cout << v1.size() << "\n";
        for (auto [x, y] : v1) {
            std::cout << x << " " << y << "\n";
        }
    }
    else {
        std::cout << v2.size() << "\n";
        for (auto [x, y] : v2) {
            std::cout << x << " " << y << "\n";
        }
    }

}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}