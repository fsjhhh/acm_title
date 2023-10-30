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
#include <array>
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

void solve()
{
	int h, w;
	std::cin >> h >> w;
    std::vector<std::string> c(h);
    for (int i = 0; i < h; i ++ ) {
    	std::cin >> c[i];
    }

    std::vector<int> cntr(h), cntc(w);
    std::vector<std::array<int, 26>> fr(h), fc(w);
    std::vector<int> disr(h), disc(w);

    for (int i = 0; i < h; i ++ ) {
    	for (int j = 0; j < w; j ++ ) {
    		cntr[i] ++ ;
    		cntc[j] ++ ;
    		int x = c[i][j] - 'a';
    		disr[i] += !fr[i][x] ++ ;
    		disc[j] += !fc[j][x] ++ ;
    	}
    }

    int resr = h, resc = w;
    std::vector<bool> st(h + w);
    std::queue<int> q;
    for (int i = 0; i < h; i ++ ) {
    	if (cntr[i] >= 2 && disr[i] == 1) {
    		q.push(i);
    	}
    }
    for (int i = 0; i < w; i ++ ) {
    	if (cntc[i] >= 2 && disc[i] == 1) {
    		q.push(h + i);
    	}
    }

    while (q.size()) {
    	auto t = q.front();
    	q.pop();
    	if (st[t]) {
    		continue;
    	}
    	st[t] = true;
    	if (t < h) {
    		resr -- ;
    		for (int i = 0; i < w; i ++ ) {
    			if (!st[h + i]) {
    				int x = c[t][i] - 'a';
    				cntc[i] -- ;
    				disc[i] -= ! -- fc[i][x];
    			}
    			if (cntc[i] >= 2 && disc[i] == 1) {
    				q.push(h + i);
    			}
    		}
    	}
    	else {
    		resc -- ;
    		t -= h;
    		for (int i = 0; i < h; i ++ ) {
    			if (!st[i]) {
    				int x = c[i][t] - 'a';
    				cntr[i] -- ;
    				disr[i] -= ! -- fr[i][x];
    			}
    			if (cntr[i] >= 2 && disr[i] == 1) {
    				q.push(i);
    			}
    		}
    	}
    }
    std::cout << resr * resc << "\n";

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