#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7, T = 20;//2^20比1e6略大，2^17比1e5略大,2^18比2e5略大 

vector<int> g[N];
int fa[N][30], dep[N]; //开到30一般肯定够深;fa[i][j]表示节点i往上2^j步到达的节点编号，一定开的比T大（30>T) 

void dfs(int x)
{
	dep[x] = dep[fa[x][0]] + 1; //fa[x][0]表示x的上一个节点 
	
	for(int i = 1; i <= T; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1]; //注意这里范围[1,T]，从小往大更新节点坐标 
	
	for(auto& y : g[x]) dfs(y); //更新完父节点再更新子节点，因为当前节点的更新是从上一个节点来的 
}

int lca(int x, int y)
{
	//使x的深度一定比y大
	if(dep[x] < dep[y]) swap(x, y);
	
	//为了让x的深度和y的深度一样 
	for(int i = T; i >= 0; i--)
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i]; //这里一定要>=，因为fa[x][i]表示x之上的节点，也就是待更新节点，
												  //如果不取等那么出来以后可能待更新节点和dep[y]深度是一样的，但是实际x深度比y更深 
	if(x == y) return x; 
	
	for(int i = T; i >= 0; i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i]; //不可能一个超出根节点fa[x][i]为0，而另一个有值，
														     //因为经过了上面的循环以后x，y的深度是一样的 
	
	return fa[x][0];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 2; i <= n; i++)
	{
		cin >> fa[i][0];
		g[fa[i][0]].push_back(i);
	}
	
	dfs(1);
	
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
