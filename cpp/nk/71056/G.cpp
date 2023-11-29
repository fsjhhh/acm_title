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
#include <bits/stdc++.h>
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

struct  dsu{
    std::vector <int> m,size;
    dsu(int n):m(n+1),size(n+1,1){std::iota(m.begin(),m.end(),0);}
    //下标从 1 开始
    int find(int x){
        while(x!=m[x]) x=m[x]=m[m[x]];
        return x;
    }
    bool same(int x,int y){return find(m[x])==find(m[y]);}
    bool merge(int x,int y){
        x=find(x),y=find(y);
        if(x == y) return false;
        size[x]+=size[y];
        m[y]=x;
        return true;
    }
    int get_size(int x){
        return size[find(x)];
    }
};

int n;

void solve() {
    std::cin >> n;
    dsu dd(n);
    int res = 0;
    for(int i=1;i<=n;i++){
        int t;
        std::cin>>t;
        dd.merge(t,i);
    }
    for(int i=1;i<=n;i++){
        res = std::max(dd.get_size(i),res);
    }
    std::cout<<res<<"\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
