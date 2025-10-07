#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//思路：对于一个根，遍历他的所有轻儿子，计算他所有轻儿子子树的贡献，每遍历完一个就删除他的所有信息
//所有轻儿子遍历完成后，走重儿子并计算其贡献，再走一遍所有轻儿子并加上自身，计算一整个树的贡献
//ps：尽可能少对重儿子的信息做处理，可以极大简化复杂度，算是启发式合并的思路 

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

//不论是Del还是New，只要cnt[col[x]]有数，st就有他的信息。
//所以，为避免同一个颜色的信息被重复加入st，每次都要检查以后判断是否erase 
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

//作用就是计算以x为根的所有子树的贡献 
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
