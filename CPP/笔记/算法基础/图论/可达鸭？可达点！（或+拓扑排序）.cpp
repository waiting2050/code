#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e3 + 7;

vector<int> g[N];
bitset<N> f[N];//定义f[j][i]为能否从i到j（为什么要反过来定义？因为题目要求的是i能到达多少个节点，若是颠倒，则之后的{1}更新逻辑有误） 
int rd[N];     //简单来说第一重循环是终点，第二重循环是起点 
			   //如果想正着写，那么在更新逻辑不变的情况下反向建图就可以 
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
	
	//拓扑排序保证了有序性，确保每次遍历的这个点的所有来路已经明确 
	while(q.size())
	{
		int x = q.front(); q.pop();
		
		for(auto& y : g[x])
		{
			f[y] |= f[x];//重要的{1}更新逻辑：已知x可以到y，那么能到x就一定能到y。直接这么写少一重循环，极大降低了复杂度 
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

