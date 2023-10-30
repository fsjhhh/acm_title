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
int primes[N], cnt = 0, s[N];
bool st[N];

void get_primes2() 
{
	st[1] = true;
	for(int i = 2; i < N; i ++ )
	{
		if(!st[i]) primes[cnt ++ ] = i;
		for(int j = 0; primes[j] <= N / i; j ++ )
		{
			st[primes[j] * i] = true;
			if(i % primes[j] == 0)
				break;
		}
	}
	for (int i = 1; i < N; i ++ ) {
		if (!st[i]) {
			s[i] = s[i - 1] + 1;
		}
		else {
			s[i] = s[i - 1];
		}
	}
}

void solve() {
    int l, r;
    std::cin >> l >> r;
    std::cout << s[r] - s[l - 1] << "\n";
}

int main() {
    IOS;
    int t = 1;
    get_primes2();
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}