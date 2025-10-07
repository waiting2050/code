#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;

vector<int> g[N];
ll a[N], sz[N], dfn[N], fa[N], son[N], dep[N], top[N], lz[N << 2], t[N << 2], P; //重链剖分的经典六个数组 
int n, idx;

void dfs1(int x, int pre)
{
	sz[x] = 1;
	fa[x] = pre;
	dep[x] = dep[pre] + 1;
	
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		dfs1(y, x);
		sz[x] += sz[y];
		if(sz[y] > sz[son[x]]) son[x] = y;
	}
}

void dfs2(int x, int t)
{
	dfn[x] = ++idx;
	top[x] = t;
	
	if(son[x]) dfs2(son[x], t);
	for(auto&y : g[x])
	{
		if(dfn[y]) continue; //重儿子和父节点已经被标记过 
		dfs2(y, y);
	}
}

void update(int s, int e, int o, ll x)
{
	t[o] += (e - s + 1ll) * x;
	lz[o] += x;
}

void pushdown(int s, int e, int o)
{
	if(!lz[o]) return;
	
	int mid = (s + e) >> 1, ls = o << 1, rs = o << 1 | 1;
	t[ls] += lz[o] * (mid - s + 1ll);
	t[rs] += lz[o] * (e - mid);
	
	lz[ls] += lz[o];
	lz[rs] += lz[o];
	
	lz[o] = 0;
}

void pushup(int o)
{
	t[o] = t[o << 1] + t[o << 1 | 1];
}

void add(int l, int r, ll x, int s = 1, int e = n, int o = 1)
{
	if(l <= s && e <= r)
	{
		update(s, e, o, x);
		return;
	}
	
	pushdown(s, e, o);
	
	int mid = (s + e) >> 1;
	if(mid >= l) add(l, r, x, s, mid, o << 1);
	if(mid + 1 <= r) add(l, r, x, mid + 1, e, o << 1 | 1);
	
	pushup(o);
}

ll query(int l, int r, int s = 1, int e = n, int o = 1)
{
	if(l <= s && e <= r) return t[o] % P;
	
	pushdown(s, e, o);

	ll res = 0;
	int mid = (s + e) >> 1;
	
	if(l <= mid) res = (res + query(l, r, s, mid, o << 1)) % P;
	if(mid + 1 <= r) res = (res + query(l, r, mid + 1, e, o << 1 | 1)) % P;
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int m, r; cin >> n >> m >> r >> P;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 2; i <= n; i++)
	{
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dfs1(r, 0);
	dfs2(r, r);
	
	for(int i = 1; i <= n; i++) add(dfn[i], dfn[i], a[i]);
	
	while(m--)
	{
		int op; cin >> op;
		
		if(op == 1)
		{
			ll x, y, z; cin >> x >> y >> z;
			
			while(top[x] != top[y])
			{
				if(dep[top[x]] < dep[top[y]]) swap(x, y);
				add(dfn[top[x]], dfn[x], z);
				x = fa[top[x]];
			}
			if(dep[x] < dep[y]) swap(x, y);
			add(dfn[y], dfn[x], z);
		}
		else if(op == 2)
		{
			ll sum = 0;
			int x, y; cin >> x >> y;
			
			while(top[x] != top[y])
			{
				if(dep[top[x]] < dep[top[y]]) swap(x, y);
				sum = (sum + query(dfn[top[x]], dfn[x])) % P;
				x = fa[top[x]];
			}
			if(dep[x] < dep[y]) swap(x, y);
			sum = (sum + query(dfn[y], dfn[x])) % P;
			
			cout << sum << '\n';
		}
		else if(op == 3)
		{
			ll x, z; cin >> x >> z;	
			add(dfn[x], dfn[x] + sz[x] - 1, z);
		}
		else 
		{
			int x; cin >> x;
			cout << query(dfn[x], dfn[x] + sz[x] - 1) % P << '\n';
		}
	}
	
	return 0;
}

//5 5 2 24
//7 3 7 8 0 
//1 2
//1 5
//3 1
//4 1
//3 4 2
//3 2 2
//4 5
//1 5 1 3
//2 1 3
//
//2
//21
