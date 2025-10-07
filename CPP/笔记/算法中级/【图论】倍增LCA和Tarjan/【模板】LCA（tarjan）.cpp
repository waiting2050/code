#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

vector<pair<int, int>> v[N];
vector<int> g[N];
int pre[N], ans[N], dep[N], fa[N]; //fa和pre同时存在，fa存储上一个节点，pre存储根节点 
bitset<N> vis;

int find(int x) {return pre[x] = (pre[x] == x ? x : find(pre[x]));}

void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	
	//确保fx一定更浅 
	if(dep[fx] > dep[fy]) swap(fx, fy);
	pre[fy] = fx; //注意这里要将深的合并到浅的 
}

void dfs(int x)
{
	dep[x] = dep[fa[x]] + 1;
	vis[x] = 1; //标记是否访问过 
	
	for(auto& y : g[x]) dfs(y);
	
	for(auto& [y, id] : v[x])
	{
		if(!vis[y]) continue; //如果没有访问过另一个节点，答案无法更新。但当更新到另一个节点时，当前已被标记过的节点就会成为答案 
		ans[id] = find(y);
	}
	
	merge(x, fa[x]); //这里要合并当前节点与上一个节点，路是一步步走的，dfs就是这样一步步更新的 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) pre[i] = i; //存储根节点 
	for(int i = 2; i <= n; i++)
	{
		cin >> fa[i]; //存储上一个节点 
		g[fa[i]].push_back(i);
	}
	
	int q; cin >> q;
	for(int i = 1; i <= q; i++) //tarjan算法仅支持离线询问，所以先将询问存储起来，并且询问的编号得记录，方便答案输出 
	{
		int x, y; cin >> x >> y;
		v[x].push_back({y, i}), v[y].push_back({x, i});
	}
	
	dfs(1); //跑一次dfs就可以获得所有lca 
	
	for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
	
	return 0;
}

// 5
// 1 1 2 3
// 3
// 1 2
// 2 4
// 1 5
// 
// 1
// 2
// 1
