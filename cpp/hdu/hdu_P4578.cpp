#include <iostream>
#include <cstdio>
 
using namespace std;
const int maxn = 100000 + 5;
const int M = 10007;
 
typedef long long ll;
 
int n, q;
int s[maxn*4], e[maxn*4];
ll sum[maxn*4][3], lazy[maxn*4][3];

 
void build(int l, int r, int rt)
{
	s[rt] = l;
	e[rt] = r;
	sum[rt][0] = sum[rt][1] = sum[rt][2] = 0;
	lazy[rt][0] = lazy[rt][2] = 0;
	lazy[rt][1] = 1;
 
	if(l != r){
		int m = (l + r) >> 1;
		build(l, m, rt << 1);
		build(m + 1, r, rt << 1 | 1);
	}
}
 
void push_down(int rt, int len)
{
	int lc = rt << 1, rc = rt << 1 | 1;
	if(lazy[rt][2]){
		lazy[lc][2] = lazy[rc][2] = lazy[rt][2];
		lazy[lc][1] = lazy[rc][1] = 1;
		lazy[lc][0] = lazy[rc][0] = 0;
 
		ll tmp = (lazy[rt][2] * lazy[rt][2] % M) * lazy[rt][2] % M;
		sum[lc][2] = tmp * (len - (len >> 1)) % M;
		sum[rc][2] = tmp * (len >> 1) % M;
 
		sum[lc][1] = (((lazy[rt][2] * lazy[rt][2]) % M) * (len - (len >> 1)) % M) % M;
		sum[rc][1] = ((lazy[rt][2] * lazy[rt][2] % M) * (len >> 1) % M) % M;
 
		sum[lc][0] = lazy[rt][2] * (len - (len >> 1)) % M;
		sum[rc][0] = lazy[rt][2] * (len >> 1) % M;
 
		lazy[rt][2] = 0;
	}
 
	if(lazy[rt][1] != 1){
		lazy[lc][1] = lazy[lc][1] * lazy[rt][1] % M;
		lazy[rc][1] = lazy[rc][1] * lazy[rt][1] % M;
		if(lazy[lc][0])	lazy[lc][0] = lazy[lc][0] * lazy[rt][1] % M;
		if(lazy[rc][0])	lazy[rc][0] = lazy[rc][0] * lazy[rt][1] % M;
 
		sum[lc][2] = sum[lc][2] * ((lazy[rt][1] * lazy[rt][1] % M) * lazy[rt][1] % M) % M;
		sum[rc][2] = sum[rc][2] * ((lazy[rt][1] * lazy[rt][1] % M) * lazy[rt][1] % M) % M;
 
		sum[lc][1] = sum[lc][1] * (lazy[rt][1] * lazy[rt][1] % M) % M;
		sum[rc][1] = sum[rc][1] * (lazy[rt][1] * lazy[rt][1] % M) % M;
 
		sum[lc][0] = sum[lc][0] * lazy[rt][1] % M;
		sum[rc][0] = sum[rc][0] * lazy[rt][1] % M;
 
		lazy[rt][1] = 1;
	}
 
	if(lazy[rt][0]){
		lazy[lc][0] += lazy[rt][0];
		lazy[rc][0] += lazy[rt][0];
 
		ll tmp = (lazy[rt][0] * lazy[rt][0] % M) * lazy[rt][0] % M;
		sum[lc][2] = (sum[lc][2] + (lazy[rt][0] * (sum[lc][1] + lazy[rt][0] * sum[lc][0] % M) % M * 3) % M
						+ (len - (len >> 1)) * tmp % M) % M;
		sum[rc][2] = (sum[rc][2] + (lazy[rt][0] * (sum[rc][1] + lazy[rt][0] * sum[rc][0] % M) % M * 3) % M
						+ (len >> 1) * tmp % M) % M;
 
		tmp = lazy[rt][0] * lazy[rt][0] % M;
		sum[lc][1] = (sum[lc][1] + 2 * (lazy[rt][0] * sum[lc][0] % M) % M +
						(len - (len >> 1)) * tmp % M) % M;
		sum[rc][1] = (sum[rc][1] + 2 * (lazy[rt][0] * sum[rc][0] % M) % M + (len >> 1) * tmp % M) % M;
 
		sum[lc][0] = (sum[lc][0] + (lazy[rt][0] * (len - (len >> 1)) % M)) % M;
		sum[rc][0] = (sum[rc][0] + (lazy[rt][0] * (len >> 1) % M)) % M;
 
		lazy[rt][0] = 0;
	}
}
 
void push_up(int rt)
{
	int lc = rt << 1, rc = rt << 1 | 1;
	sum[rt][0] = (sum[lc][0] + sum[rc][0]) % M;
	sum[rt][1] = (sum[lc][1] + sum[rc][1]) % M;
	sum[rt][2] = (sum[lc][2] + sum[rc][2]) % M;
}
 
void update(int t, int c, int st, int ed, int rt)
{
	int len = ed - st + 1;
	if(s[rt] == st && e[rt] == ed){
		if(t == 2){
			lazy[rt][2] = c;
			lazy[rt][1] = 1;
			lazy[rt][0] = 0;
			sum[rt][0] = (c*(ed-st+1))%M;
			sum[rt][1] = ((c * c % M) * (ed - st + 1)) % M;
			sum[rt][2] = (((c * c) % M) * c % M) * (ed - st + 1) % M;
		}
		else if(t == 1){
			lazy[rt][1] = lazy[rt][1] * c % M;
			if(lazy[rt][0])	lazy[rt][0] = lazy[rt][0] * c % M;
			sum[rt][0] = sum[rt][0] * c % M;
			sum[rt][1] = (c * c % M) * sum[rt][1] % M;
			sum[rt][2] = ((c * c % M) * c % M) * sum[rt][2] % M;
		}
		else if(t == 0){
			lazy[rt][0] = (lazy[rt][0] + c) % M;
			sum[rt][2] = (sum[rt][2] + (sum[rt][1] + c * sum[rt][0] % M) * 3 * c % M +
							((((len * c) % M) * c % M) * c % M)) % M;
			sum[rt][1] = (sum[rt][1] + (sum[rt][0] * c % M) * 2 % M + (len * c % M) * c % M) % M;
			sum[rt][0] = (sum[rt][0] + c * len % M) % M;
		}
		return;
	}
	if(s[rt] == e[rt])	return;
 
	push_down(rt, e[rt] - s[rt] + 1);
 
	int m = (s[rt] + e[rt]) >> 1;
	if(ed <= m)	update(t, c, st, ed, rt << 1);
	else if(st > m)	update(t, c, st, ed, rt << 1 | 1);
	else{
		update(t, c, st, m, rt << 1);
		update(t, c, m+1, ed, rt << 1 | 1);
	}
	push_up(rt);
}
 
ll query(int p, int l, int r, int rt)
{
	if(s[rt] == l && e[rt] == r){
		return sum[rt][p] % M;
	}
 
	push_down(rt, e[rt] - s[rt] + 1);
 
	int m = (s[rt] + e[rt]) >> 1;
	ll res = 0;
 
	if(r <= m)	res += query(p, l, r, rt << 1) % M;
	else if(l > m)	res += query(p, l ,r, rt << 1 | 1) % M;
	else{
		res += query(p, l, m, rt << 1) % M;
		res += query(p, m+1, r, rt << 1 | 1) % M;
	}
	return res % M;
}
 
int main()
{
	while(~scanf("%d%d", &n, &q)){
		if(n == 0 && q == 0)	break;
 
		build(1, n, 1);
 
		while(q--){
			int op, a, b, c;
			scanf("%d%d%d%d", &op, &a, &b, &c);
 
			if(op == 4){
				printf("%lld\n", query(c-1, a, b, 1) % M);
			}else{
				update(op-1, c, a, b, 1);
			}
		}
	}
}