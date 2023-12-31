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

typedef unsigned long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    std::string s;
    std::cin >> s;
    LL x = 0, y = 0;
    bool pd = false;
    for (int i = 0, j = 0; i < s.size(); i ++ ) {
    	if (s[i] >= '0' && s[i] <= '9') {
    		if (!pd) {
    			x = x * 10 + s[i] - '0';
    		}
    		else {
    			y = y * 10 + s[i] - '0';
    		}
    	}
    	if (s[i] == '^') {
    		pd = true;
    	}
    }

    LL ans = 1;
    pd = false;
    if (x != 1) {
		for (int i = 1; i <= y; i ++ ) {
			ans *= x;
			if (ans > 1000000000000000000) {
				pd = true;
				break;
			}
		}
	}
    

    std::string d[10][10]={"........","........","........","........","........","........","........","........","........","........","........","........","........","........","........","........","........","........","........","........","0000000.","......1.","2222222.","3333333.","4.....4.","5555555.","6666666.","7777777.","8888888.","9999999.","0.....0.","......1.","......2.","......3.","4.....4.","5.......","6.......","......7.","8.....8.","9.....9.","0.....0.","......1.","......2.","......3.","4.....4.","5.......","6.......","......7.","8.....8.","9.....9.","0.....0.","......1.","2222222.","3333333.","4444444.","5555555.","6666666.","......7.","8888888.","9999999.","0.....0.","......1.","2.......","......3.","......4.","......5.","6.....6.","......7.","8.....8.","......9.","0.....0.","......1.","2.......","......3.","......4.","......5.","6.....6.","......7.","8.....8.","......9.","0000000.","......1.","2222222.","3333333.","......4.","5555555.","6666666.","......7.","8888888.","9999999.","........","........","........","........","........","........","........","........","........","........"};
	std::string z[10][10]={"......","......","......","......","......","......","......","......","......","......","00000.","....1.","22222.","33333.","4...4.","55555.","66666.","77777.","88888.","99999.","0...0.","....1.","....2.","....3.","4...4.","5.....","6.....","....7.","8...8.","9...9.","0...0.","....1.","22222.","33333.","44444.","55555.","66666.","....7.","88888.","99999.","0...0.","....1.","2.....","....3.","....4.","....5.","6...6.","....7.","8...8.","....9.","00000.","....1.","22222.","33333.","....4.","55555.","66666.","....7.","88888.","99999.","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......","......"};
	std::string f[10][2]={"........","........................","........","........................","........","IIIIIII.N.....N.FFFFFFF.","........","...I....NN....N.F.......","=======.","...I....N.N...N.F.......","........","...I....N..N..N.FFFFFFF.","=======.","...I....N...N.N.F.......","........","...I....N....NN.F.......","........","IIIIIII.N.....N.F.......","........","........................"};

	std::string dd = std::to_string(x);
	std::string zz = std::to_string(y);
	std::string an;
	if (pd) {
		an = "I";
	}
	else {
		an = std::to_string(ans);
	}
	std::string re = dd + "." + zz + "=" + an;
	for (int i = 0; i < 10; i ++ ) {
		std::cout << '.';
		bool pd = false;
		for (int j = 0; j < re.size(); j ++ ) {
			if (re[j] == '=') {
				std::cout << f[i][0];
				pd = false;
			}
			if (re[j] == '.') {
				pd = true;
			}
			if (re[j] == 'I') {
				std::cout << f[i][1];
			}
			if (re[j] >= '0' && re[j] <= '9') {
				if (!pd) {
					std::cout << d[i][re[j] - '0'];
				}
				else {
					std::cout << z[i][re[j] - '0'];
				}
			}
		}
		std::cout << "\n";
	} 
	std::cout << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}