#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//˼·������һ����������������������ӣ���������������������Ĺ��ף�ÿ������һ����ɾ������������Ϣ
//��������ӱ�����ɺ����ض��Ӳ������乱�ף�����һ����������Ӳ�������������һ�������Ĺ���
//ps���������ٶ��ض��ӵ���Ϣ���������Լ���򻯸��Ӷȣ���������ʽ�ϲ���˼· 

const int N = 2e5 + 7;

vector<int> g[N];
ll ans;
int sz[N], son[N], col[N], cnt[N];
multiset<int> st;

void dfs(int x)
{
	sz[x] = 1;
	
	for(auto& y : g[x])
	{
		dfs(y);
		sz[x] += sz[y];
		if(sz[y] > sz[son[x]]) son[x] = y;
	}
}

//������Del����New��ֻҪcnt[col[x]]������st����������Ϣ��
//���ԣ�Ϊ����ͬһ����ɫ����Ϣ���ظ�����st��ÿ�ζ�Ҫ����Ժ��ж��Ƿ�erase 
void NewNode(int x)
{
	if(cnt[col[x]]) st.erase(st.find(cnt[col[x]]));
	st.insert(++cnt[col[x]]);
}

void NewNodeTree(int x)
{
	NewNode(x);
	for(auto& y : g[x]) NewNodeTree(y);
}

void DelNode(int x)
{
	if(cnt[col[x]]) st.erase(st.find(cnt[col[x]]));
	if(--cnt[col[x]]) st.insert(cnt[col[x]]);
}

void DelNodeTree(int x)
{
	DelNode(x);
	for(auto& y : g[x]) DelNodeTree(y);
}

//���þ��Ǽ�����xΪ�������������Ĺ��� 
void dfs1(int x)
{
	for(auto& y : g[x])
	{
		if(son[x] == y) continue;
		dfs1(y);
		DelNodeTree(y);
	}
	
	if(son[x]) dfs1(son[x]);
	NewNode(x);
	for(auto& y :g[x])
	{
		if(y == son[x]) continue;
		NewNodeTree(y);
	}
	
	if(*st.begin() == *st.rbegin()) ans++;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int f; cin >> col[i] >> f;
		g[f].push_back(i);
	}
	
	dfs(1);
	dfs1(1);
	
	cout << ans;
	
	return 0;
}

// 6
// 2 0
// 2 1
// 1 2
// 3 3
// 3 4
// 1 4
// 
// 4
