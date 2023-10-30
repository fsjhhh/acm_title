#include <iostream>
#include <cstring>
#include <algorithm>
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 510, M = 1e5 + 10;
struct Ege
{
	int a, b, w;
}edgs[M]; // �洢�� 

int n, m, k;
int dist[M], backup[M]; 

int bellman_ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 1; i <= k; i ++ )
	{
		memcpy(backup, dist, sizeof dist); // ���ݣ� ��ֹ���� 
		for(int j = 1; j <= m; j ++ )
		{
			int a = edgs[j].a, b = edgs[j].b, w = edgs[j].w;
			if(dist[b] > backup[a] + w)
				dist[b] = backup[a] + w; // ���¾��� 
		}
	}
	
	if(dist[n] > 0x3f3f3f3f / 2) return -0x3f3f3f; //����дdist[n] == 0x3f3f3f3f, ���ܳ���n-1 -> n Ϊ��Ȩ
												   //���ܷ��ؽ�С����������dist[n]����Ϊ��С���� 
	else return dist[n];
	
}

void solve()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b, w;
		cin >> a >> b >> w;
		edgs[i] = {a, b, w};
	}
	
	int t = bellman_ford();
	
	if(t == -0x3f3f3f) cout << "impossible" << endl;
	else cout << t << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

