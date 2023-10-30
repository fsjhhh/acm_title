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

const int N = 1e5 + 10, mod = 1e9 + 7;
int primes[N];

class Solution {
public:
    void init() {
        for (int i = 2; i < N; i ++ ) {
            if (!primes[i]) {
                for (int j = i; j < N; j += i) {
                    primes[j] ++ ;
                }
            }
        }
    }
    bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
    LL power(LL a, LL b) {
        LL res = 1;
        while (b) {
            if (b & 1) {
                res = res * a % mod; 
            }
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    int maximumScore(std::vector<int>& nums, int k) {
        init();
        int n = nums.size();
        std::vector<std::pair<int, int>> v;
        std::vector<int> left(n, -1), right(n, n);
        std::vector<int> st;
        for (int i = 0; i < n; i ++ ) {
            while (st.size() && primes[nums[st.back()]] < primes[nums[i]]) {
                right[st.back()] = i;
                st.pop_back();
            }
            if (st.size()) {
                left[i] = st.back();
            }
            st.push_back(i);
            v.push_back({nums[i], i});
        }
        for (int i = 0; i < n; i ++ ) {
            // if (left[i] == -1) {
            //     left[i] = i - 1;
            // }
            // if (right[i] == n) {
            //     right[i] = i + 1;
            // }
            std::cout << nums[i] << " " << left[i] << " " << right[i] << " " << primes[nums[i]] << "\n";
        }

        LL ans = 1;
        std::sort(v.begin(), v.end(), std::greater<PII>());
        for (auto [val, id] : v) {
            LL total = (id - left[id]) * (right[id] - id);
            if (total >= k) {
                total = k;
                ans = ans * power(val, total) % mod;
                k = 0;
                break;
            }
            else {
                k -= total;
                ans = ans * power(val, total) % mod;
            }
        }
        return ans;
    }
};

void solve()
{
	int n = 5;
    std::vector<int> v = {8, 3, 9, 3, 8};
    Solution sol;
    std::cout << sol.maximumScore(v, 2) << "\n";
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