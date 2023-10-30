#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int N = 1e5 + 10;
int h[N], e[N], w[N], ne[N], idx;
int n, m, dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool spfa()
{
	//memset(dist, 0x3f, sizeof dist);
	//dist[1] = 0;
	//��ʼ��Ϊ0��dist[j] > dist[t] + w[i] ����Ҫ�ȵ��и�Ȩ�߲ŻῪʼ����
	//��Ȩ�߲��ǹؼ����ؼ��Ǹ�����dist ���Գ�ʼ����Ҳ���Բ���ʼ����dist ��ʼֵ�Ĵ�С��Ӱ�����ս��
 	
	queue<int> q;
	
	for(int i = 1; i <= n; i ++ ) //��ֹ���ֲ�����ͨ��ͼ����һЩ�������鲻�� 
	{
		st[i] = true;
		q.push(i);
	}
	
	while(q.size())
	{
		int t = q.front();
		q.pop();
		
		st[t] = false;
		
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if(cnt[j] >= n)
					return true;
				if(!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	
	if(spfa()) cout << "Yes" << endl;
	else cout << "No" << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

