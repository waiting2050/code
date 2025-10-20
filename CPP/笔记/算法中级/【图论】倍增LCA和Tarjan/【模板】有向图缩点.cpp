#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

vector<int> g[N], v;
int dfn[N]; //记录节点时间戳，标记是否走过 
int low[N]; //存储节点能到达的的回点（一个走过的点）的最小时间戳
int stk[N], top; //一个栈，存储走过的且没有被染色的点
int col[N]; //存储节点的颜色
int c[N]; //本题用来记录每种颜色数量的数组 
int tot; //表示此时的颜色总数
int idx; //此时的时间戳 
bitset<N> ins; //即instack，是否在栈中 
//回点：形式化的讲，即dfn不为0且在栈中。通俗的理解，即与入点在一个缩点且父亲是别的点 

void tarjan(int x) //tarjan的本质是一种dfs 
{
	// 1.初始化dfn和low 
	dfn[x] = low[x] = ++idx;
	
	// 2.入栈并标记 
	stk[++top] = x;
	ins[x] = 1;
	
	// 3.遍历所有出点（是出点不是儿子，u可能指向很多v，但v只能有一个父亲） 
	for(auto& y : g[x])
	{
		//判断是否是回点 
		if(!dfn[y]) //如果这个点没访问，那y就是x的儿子 
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(ins[y]) low[x] = min(low[x], dfn[y]); //这个点访问过了且在栈里面
		//反之，一个点访问过又不在栈里面，那这个点在别的缩点里 
	}
	
	if(dfn[x] == low[x]) //判断是否构成缩点 
	{
		tot++; //新开一个颜色 
		while(stk[top + 1] != x)
		{
			col[stk[top]] = tot; //染色 
			c[tot]++;  
			
			ins[stk[top--]] = 0; //取消标记并出栈 
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	while(m--)
	{
		int x, y; cin >> x >> y;
		g[x].push_back(y);
	}
	
	for(int i = 1; i <= n; i++) //1不一定是最终的根节点，要考虑每一个点为根节点的可能 
		if(!dfn[i]) tarjan(i);
		
	for(int i = 1; i <= tot; i++)
		if(c[i] > 1) v.push_back(c[i]);
	
	if(v.size())
	{
		sort(v.begin(), v.end());
		for(auto& y : v) cout << y << ' ';
	}
	else cout << -1;
	
	return 0;
}

//4 4
//1 2
//2 3
//3 1
//1 4
//
//3
