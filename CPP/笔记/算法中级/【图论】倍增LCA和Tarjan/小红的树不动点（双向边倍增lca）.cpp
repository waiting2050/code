// Problem: С�����������
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/114848/F
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//�������ٵ���һ��1��Ȼ������乱�ף��������м������ڵ�͹��׼��Σ����൱��dep[lca(1,1)]��������2��1,2����ͬʱ���ڣ�����ʱ��1,2��lca����� 
//�Դ����ƣ�����lca(lca(1,2),3) 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7, T = 20;

vector<int> g[N];
int fa[N][30], dep[N]; //fa��ά���ĵñ�T�󣬷���ᳬ����Χ��Ѫ�Ľ�ѵ�� 

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
	for(int i = 2; i <= n; i++) //����û����ȷ���򣬴洢˫��� 
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(n, 0); //���������һ����������������Ϊ�����ٸ�������������1Ϊ������ôdep[1]�Ĺ��׽����С��ѡ������Ҳ�ǡ� 
			   //��Ϊ��������������lcaһ���Ǹ�������ôdep��Զ��1������Խ���lca�Ƶ���Խ�� 
	
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
