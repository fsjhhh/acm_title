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

std::map<int, std::string> chn = {
    {0, "零"},
    {1, "壹"},
    {2, "贰"},
    {3, "叁"},
    {4, "肆"},
    {5, "伍"},
    {6, "陆"},
    {7, "柒"},
    {8, "捌"},
    {9, "玖"}
};

std::vector<std::string> un = {"", "拾", "佰", "仟"};

std::string change(LL num) {
    std::string res;

    std::string w = std::to_string(num);
    int n = w.size();

    int cnt = 0;
    bool pd = false;
    for (int i = n - 1; i >= 0; i--) {
        if (cnt == 4) {
            res = "万" + res;
            pd = false;
            cnt = 0;
        }
        if (w[i] != '0') {
            pd = true;
            if (cnt == 0) {
                res = chn[w[i] - '0'] + res; 
            } else {
                res = un[cnt] + res;
                res = chn[w[i] - '0'] + res;
            }
            cnt ++ ;
        } else {
            if (pd) {
                res = chn[0] + res;
                pd = false;
            }
            cnt ++ ;
        }
        
    }

    // std::reverse(res.begin(), res.end());
    
//     std::string ans;
//     for (int i = (int)res.size() - 1; i >= 0; i--) {
//         ans += res[i];
//     }
    
    return res;

}

void solve() {
    double s;
    while (std::cin >> s) {
        LL z = s;
        std::string k = change(z);
        if (k.size()) {
            k += "元";
        }
        
        double m = s - z;
        if (m == 0) {
            std::cout << k << "整\n";
            continue;
        } else {
            //m *= 100;
            std::string t = std::to_string(m);
            //std::cout << t << "\n";
            if (t[2] == '0') {
                k += chn[0];
            } else {
                k += chn[t[2] - '0'];
                k += "角";
            }
            if (t[3] != '0') {
                k += chn[t[3] - '0'];
                k += "分";
            }
        }
        std::cout << k << "\n";
    }
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}