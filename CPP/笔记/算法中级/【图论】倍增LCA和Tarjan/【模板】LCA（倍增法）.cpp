#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7, T = 20;//2^20��1e6�Դ�2^17��1e5�Դ�,2^18��2e5�Դ� 

vector<int> g[N];
int fa[N][30], dep[N]; //����30һ��϶�����;fa[i][j]��ʾ�ڵ�i����2^j������Ľڵ��ţ�һ�����ı�T��30>T) 

void dfs(int x)
{
	dep[x] = dep[fa[x][0]] + 1; //fa[x][0]��ʾx����һ���ڵ� 
	
	for(int i = 1; i <= T; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1]; //ע�����ﷶΧ[1,T]����С������½ڵ����� 
	
	for(auto& y : g[x]) dfs(y); //�����길�ڵ��ٸ����ӽڵ㣬��Ϊ��ǰ�ڵ�ĸ����Ǵ���һ���ڵ����� 
}

int lca(int x, int y)
{
	//ʹx�����һ����y��
	if(dep[x] < dep[y]) swap(x, y);
	
	//Ϊ����x����Ⱥ�y�����һ�� 
	for(int i = T; i >= 0; i--)
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i]; //����һ��Ҫ>=����Ϊfa[x][i]��ʾx֮�ϵĽڵ㣬Ҳ���Ǵ����½ڵ㣬
												  //�����ȡ����ô�����Ժ���ܴ����½ڵ��dep[y]�����һ���ģ�����ʵ��x��ȱ�y���� 
	if(x == y) return x; 
	
	for(int i = T; i >= 0; i--)
		if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i]; //������һ���������ڵ�fa[x][i]Ϊ0������һ����ֵ��
														     //��Ϊ�����������ѭ���Ժ�x��y�������һ���� 
	
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
