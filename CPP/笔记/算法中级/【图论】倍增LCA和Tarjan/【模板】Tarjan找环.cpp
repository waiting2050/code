#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//双向图找环和单向图找缩点的代码是一样的，只是建图的时候是双向，tarjan多一个pre变量 

const int N = 2e5 + 7;

vector<int> g[N];
int dfn[N], low[N], stk[N], idx, top, cnt;
bitset<N> ins;

void tarjan(int x, int pre)
{
	dfn[x] = low[x] = ++idx;
	stk[++top] = x;
	ins[x] = 1;
	
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		if(!dfn[y])
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
		}
		else if(ins[y]) low[x] = min(low[x], dfn[y]);
	}
	
	if(dfn[x] == low[x])
	{
		int tmp = 0;
		while(stk[top + 1] != x)
		{
			tmp++;
			ins[stk[top--]] = 0;
		}
		
		if(tmp > cnt) cnt = tmp;
	}
}

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		g[i].clear();
		stk[i] = dfn[i] = low[i] = 0;
		ins[i] = 0;
	}
	stk[n + 1] = 0;
	cnt = top = 0;
	
	for(int i = 1; i <= n; i++)
	{
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	tarjan(1, 0);
	
	cout << cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

// 2
// 5
// 1 2
// 1 3
// 2 3
// 3 4
// 4 5
// 4
// 1 2
// 2 3
// 3 4
// 1 4
// 
// 3
// 4
