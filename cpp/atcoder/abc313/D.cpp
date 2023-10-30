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

const int N = 1010;
int a[N], T[N], S[N];

void solve()
{
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= k; i ++ ) {
		std::cout << "?";
		for (int j = 1; j <= k + 1; j ++ ) {
			if (j != i) {
				std::cout << " " << j;
			}
		}
		std::cout << std::endl;
		std::cin >> T[i];
	}
	for (int i = 1; i <= n - k + 1; i ++ ) {
		if (i != 2) {
			std::cout << "?";
			for (int j = i; j <= k + i - 1; j ++ ) {
				std::cout << " " << j;
			}
			std::cout << std::endl;
			std::cin >> S[i];
		}
		else {
			S[i] = T[1];
		}
	}
	int _1 = 0;
	for (int i = 1; i <= k; i ++ ) {
		if (T[i] == T[1]) {
			_1 ++ ;
		}
	}
	if (S[1] % 2) {
		if (_1 % 2) {
			a[1] = 1;
		}
		else {
			a[1] = 0;
		}
	}
	else {
		if (_1 % 2) {
			a[1] = 0;
		}
		else {
			a[1] = 1;
		}
	}

	for (int i = 2; i <= k; i ++ ) {
		if (T[i] == T[1]) {
			a[i] = a[1];
		}
		else {
			a[i] = (a[1] + 1) % 2;
		}
	}

	for (int i = 2; i <= n - k + 1; i ++ ) {
		if (S[i] == S[i - 1]) {
			a[k + i - 1] = a[i - 1];
		}
		else {
			a[k + i - 1] = (a[i - 1] + 1) % 2;
		}
	}

	std::cout << "!";
	for (int i = 1; i <= n; i ++ ) {
		std::cout << " " << a[i];
	}
	std::cout << std::endl;

}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}