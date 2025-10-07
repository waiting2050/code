#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

vector<pair<int, int>> v[N];
vector<int> g[N];
int pre[N], ans[N], dep[N], fa[N]; //fa��preͬʱ���ڣ�fa�洢��һ���ڵ㣬pre�洢���ڵ� 
bitset<N> vis;

int find(int x) {return pre[x] = (pre[x] == x ? x : find(pre[x]));}

void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	
	//ȷ��fxһ����ǳ 
	if(dep[fx] > dep[fy]) swap(fx, fy);
	pre[fy] = fx; //ע������Ҫ����ĺϲ���ǳ�� 
}

void dfs(int x)
{
	dep[x] = dep[fa[x]] + 1;
	vis[x] = 1; //����Ƿ���ʹ� 
	
	for(auto& y : g[x]) dfs(y);
	
	for(auto& [y, id] : v[x])
	{
		if(!vis[y]) continue; //���û�з��ʹ���һ���ڵ㣬���޷����¡��������µ���һ���ڵ�ʱ����ǰ�ѱ���ǹ��Ľڵ�ͻ��Ϊ�� 
		ans[id] = find(y);
	}
	
	merge(x, fa[x]); //����Ҫ�ϲ���ǰ�ڵ�����һ���ڵ㣬·��һ�����ߵģ�dfs��������һ�������µ� 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) pre[i] = i; //�洢���ڵ� 
	for(int i = 2; i <= n; i++)
	{
		cin >> fa[i]; //�洢��һ���ڵ� 
		g[fa[i]].push_back(i);
	}
	
	int q; cin >> q;
	for(int i = 1; i <= q; i++) //tarjan�㷨��֧������ѯ�ʣ������Ƚ�ѯ�ʴ洢����������ѯ�ʵı�ŵü�¼���������� 
	{
		int x, y; cin >> x >> y;
		v[x].push_back({y, i}), v[y].push_back({x, i});
	}
	
	dfs(1); //��һ��dfs�Ϳ��Ի������lca 
	
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
