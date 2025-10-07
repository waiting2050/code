// Problem: 小红的树不动点
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/114848/F
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//子树至少得有一个1，然后计算其贡献，发现他有几个根节点就贡献几次（就相当于dep[lca(1,1)]）。再找2（1,2必须同时存在），此时找1,2的lca的深度 
//以此类推，再找lca(lca(1,2),3) 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7, T = 20;

vector<int> g[N];
int fa[N][30], dep[N]; //fa二维开的得比T大，否则会超出范围（血的教训） 

void dfs(int x, int pre)
{
	dep[x] = dep[pre] + 1;
	fa[x][0] = pre;
	
	for(int i = 1; i <= T; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		dfs(y, x);
	}
}

int lca(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	
	for(int i = T; i >= 0; i--) 
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	
	if(x == y) return x;
	
	for(int i = T; i >= 0; i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
		
	return fa[x][0];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 2; i <= n; i++) //发现没有明确方向，存储双向边 
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(n, 0); //不是随便找一个根，得让最大的数为根。举个反例，假如让1为根，那么dep[1]的贡献将会很小，选其他的也是。 
			   //因为根和其他的数的lca一定是根本身，那么dep永远是1，所以越晚吧lca推到根越好 
	
	int o = 1;
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		o = lca(o, i), ans += dep[o];
	
	cout << ans;
	
	return 0;
}

//4
//3 4
//2 4
//1 2
//
//7
//
//
//4
//1 3
//2 3
//4 3
//
//8
