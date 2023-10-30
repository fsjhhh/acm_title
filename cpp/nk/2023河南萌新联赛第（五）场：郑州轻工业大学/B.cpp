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

void solve()
{
    int n;
    std::cin >> n;
    std::set<std::string> s, st;
    for (int i = 1; i <= n; i ++ ) {
    	std::string s1, s2;
    	std::cin >> s1 >> s2;
    	if (s1 == "sudo") {
    		if (s2 == "pacman") {
    			std::string s3, s4;
    			std::cin >> s3 >> s4;
    			s.insert(s4);
                st.insert(s4);
    		}
    		else {
    			std::cout << "wuwuwu" << "\n";
    			return ;
    		}
    	}
    	else if (s1 == "1") {
    		if (s.find(s2) != s.end()) {
    			std::cout << "yes" << "\n";
    		}
    		else {
    			std::cout << "no" << "\n";
    		}
    	}
        else if (s1 == "2") {
            if (st.find(s2) != st.end()) {
                std::cout << "yes" << "\n";
            }
            else {
                std::cout << "no" << "\n";
            }
        }
    	else {
    		std::string s3;
    		std::cin >> s3;
    	    if (s2 == "-R") {
                s.erase(s3);
            }
            else {
                s.erase(s3);
                st.erase(s3);
            }
    	}
    }
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