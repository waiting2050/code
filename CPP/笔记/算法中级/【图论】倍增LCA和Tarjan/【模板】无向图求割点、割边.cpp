#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

vector<int> g[N];
int dfn[N], low[N], idx, cut, es;

//首先我们要明确，割点仅存在于无向图中，并且在无向图中判断强联通分量没有意义（因为任意一个无
//向的联通块一定是强联通的）。所以我们不需要col，stk，也不需要tot,top了

//我们先定义一个x的"不回儿子y”，意思在y的子树中，不存在任意一个点可以回到x的父亲链上

//割点有两种情况 
//1.点c是此次tarjan的根，那么c只要存在两个及以上的不回儿子y，就可以说明，是一个割点
//2.点r不是此次tarjan的根，那么c只需要存在一个不回儿子（想象其父亲所在联通块构成了一个不回儿子），就可以说明c是一个割点
//ps:需要注意，我们的tarjan过程会构成一棵搜索树，只有满足!dfny的儿子y才能被称作为儿子，才有资格判断是否是"不回儿子"

//割边： 
//求割边非常简单，仅需在tarjan的过程中，不走父亲这条回边，然后判断儿子结点是否是一个连自身都回
//不到的儿子（即儿子内部形成了一个和自身以及父亲链无关的强联通分量，等价于low[y]〉df[x])即可。

void tarjanp(int x, int pre)
{
	dfn[x] = low[x] = ++idx;
	
	int child = 0;
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		if(!dfn[y]) 
		{
			tarjanp(y, x);
			low[x] = min(low[x], low[y]);
			child += low[y] >= dfn[x]; 
		}
		else low[x] = min(low[x], dfn[y]);
	}
	
	if(child >= 2 && !pre || child && pre) cut++;
}


void tarjans(int x, int pre)
{
	dfn[x] = low[x] = ++idx;
	
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		if(!dfn[y]) 
		{
			tarjans(y, x);
			low[x] = min(low[x], low[y]);
			es += low[y] > dfn[x]; //如果y不回到自身及父亲树上 
		}
		else low[x] = min(low[x], dfn[y]);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	while(m--)
	{
		int x, y; cin >> x >> y;
		g[x].push_back(y), g[y].push_back(x);
	}
	
	tarjanp(1, 0);
	
	idx = 0;
	for(int i = 1; i <= n; i++) dfn[i] = low[i] = 0;
	tarjans(1, 0);
	
	cout << cut << ' ' << es;
	
	return 0;
}

//4 4
//1 2
//3 2
//2 4
//1 3
//
//1 1
