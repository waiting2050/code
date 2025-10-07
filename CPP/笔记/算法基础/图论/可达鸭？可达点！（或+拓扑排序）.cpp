#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3 + 7;

vector<int> g[N];
bitset<N> f[N];//����f[j][i]Ϊ�ܷ��i��j��ΪʲôҪ���������壿��Ϊ��ĿҪ�����i�ܵ�����ٸ��ڵ㣬���ǵߵ�����֮���{1}�����߼����� 
int rd[N];     //����˵��һ��ѭ�����յ㣬�ڶ���ѭ������� 
			   //���������д����ô�ڸ����߼����������·���ͼ�Ϳ��� 
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	for(int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		rd[v]++;
	}
	
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(!rd[i]) q.push(i);
	
	for(int i = 1; i <= n; i++) f[i][i] = 1;
	
	//��������֤�������ԣ�ȷ��ÿ�α�����������������·�Ѿ���ȷ 
	while(q.size())
	{
		int x = q.front(); q.pop();
		
		for(auto& y : g[x])
		{
			f[y] |= f[x];//��Ҫ��{1}�����߼�����֪x���Ե�y����ô�ܵ�x��һ���ܵ�y��ֱ����ôд��һ��ѭ�������󽵵��˸��Ӷ� 
			if(!--rd[y]) q.push(y);
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		int cnt = 0;
		
		for(int j = 1; j <= n; j++)
		{
			if(f[j][i]) cnt++;
		}
		
		cout << cnt << ' ';
	}
	
	return 0;
}

