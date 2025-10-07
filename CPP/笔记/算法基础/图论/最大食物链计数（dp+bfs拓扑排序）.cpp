// Problem: Luogu P4017
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4017
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//拓扑排序： 
//在图论中，拓扑排序（Topological Sorting）是一个有向无环图（DAG, Directed Acyclic Graph）的所有顶点的线性序列。且该序列必须满足下面两个条件：
//1.每个顶点出现且只出现一次。
//2.若存在一条从顶点 A 到顶点 B 的路径，那么在序列中顶点 A 出现在顶点 B 的前面。
//功能：在搜索x前，把能到达x的所有节点yi都先处理一遍 
//拓扑排序通常用来“排序”具有依赖关系的任务，关键是要维护一个入度为0的顶点的集合。

//总结一下，此种拓扑排序共有四个主要步骤：
//1.初始化队列，将入度为 0 的节点放入队列。
//2.取出队首，遍历其出边，将能够到达的点入度减一，同时维护答案数组。
//3.若在此时一个点的入度变为 0，那么将其加入队列。
//4.回到第二步，直到队列为空。

//一般有两种方法判断能否拓扑排序：
//1.从1~n，有某一个rd[i]!=0
//2.拓扑链总长度不为n 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 80112002;

const int N = 5e3 + 7;

int rd[N], cd[N], dp[N];//入度，出度，食物链计数数组 
vector<int> g[N];//存图 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int a, b; cin >> a >> b;//a被b吃，即a->b（故a为出，b为入） 
		rd[b]++, cd[a]++;//b的入度+1，即指向b的路径数+1；a的出度+1，即从a出发的路径+1 
		g[a].push_back(b);
	}
	
	queue<int> q;//bfs的队列 
	for(int i = 1; i <= n; i++)
	{
		if(!rd[i])//如果入度为0则加入队列，并将其本身食物链数记为1 
		{
			q.push(i);
			dp[i] = 1;
		}
	}
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		
		for(auto& y : g[t])
		{
			dp[y] = (dp[y] + dp[t]) % MOD;//出点的食物链数=本身有的+新增的 
			rd[y]--;//每次累加后，将其入点-1 
			if(!rd[y]) q.push(y);//当该点没有入点，可以让它也入队（维护入度为0的点的集合） 
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!cd[i])//如果没有出点，说明他是最终的捕食者 
		 ans = (ans + dp[i]) % MOD;
	}
	
	cout << ans;
	
	return 0;
}

// 5 7
// 1 2
// 1 3
// 2 3
// 3 5
// 2 5
// 4 5
// 3 4
// 
// 5
