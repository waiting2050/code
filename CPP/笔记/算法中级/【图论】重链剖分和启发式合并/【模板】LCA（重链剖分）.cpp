#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

vector<int> g[N];
int fa[N], top[N], son[N], sz[N], dep[N];

//求深度，求节点数sz，在递归回来时求重儿子 
void dfs(int x)
{
	dep[x] = dep[fa[x]] + 1;
	sz[x] = 1;
	
	for(auto& y : g[x])
	{
		dfs(y);
		sz[x] += sz[y]; 
		if(sz[y] > sz[son[x]]) son[x] = y;
	}
}

//求重链 
void dfs(int x, int t) //x是当前节点，t是链顶 
{
	top[x] = t;
	
	//求重儿子 
	if(son[x]) dfs(son[x], t);
	
	for(auto& y : g[x])
	{
		if(y == son[x]) continue;
		dfs(y, y); //轻儿子 
	}
}

int lca(int x, int y)
{	
	while(top[x] != top[y]) //只要不在同一条重链上 
	{
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]]; //将深度偏大的往上跳 
	}
	
	if(dep[x] < dep[y]) swap(x, y); //已经在同一条链上，返回深度小的 
	
	return y;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 2; i <= n; i++)
	{
		cin >> fa[i];
		g[fa[i]].push_back(i);
	}
	
	dfs(1);
	dfs(1, 1);
	
	int q; cin >> q;
	while(q--)
	{
		int u, v; cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
	
	return 0;
}

//5
//1 1 2 3
//3
//1 2
//2 4
//1 5
//
//1
//2
//1
