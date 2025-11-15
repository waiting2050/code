// Problem: 明弦音
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/122725/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 题目中所有关系都由等式约束，容易想到用带权并查集，再路径压缩优化即可。当op=1时，本来应该连u,v，但是并查集所有操作在根上进行，
// 于是想办法连fu与fv（注意带权并查集的边是有向边，连边时方向由正负号体现）。op=2时，建立虚拟源点0，将0当做v，其余操作与op=1一致。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 5e5 + 7;

int pre[N], n;
ll d[N];

void init() {for(int i = 0; i <= n; i++) pre[i] = i, d[i] = 0;}

int find(int x)
{
	if(pre[x] == x) return x;
	
	int fx = pre[x];
	pre[x] = find(pre[x]);
	d[x] += d[fx];
	
	return pre[x];
}

void merge(int x, int y, ll k)
{
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	pre[fx] = fy, d[fx] = d[y] + k - d[x];
}

void solve()
{
	int q; cin >> n >> q;
	init();
	
	while(q--)
	{
		int op; cin >> op;
		if(op == 1)
		{
			int u, v; cin >> u >> v;
			ll k; cin >> k;
			
			if(find(u) == find(v))
			{
				if(d[u] - d[v] != k) cout << "CONTRADICTION\n";
				else cout << "OK\n";
			}
			else
			{
				cout << "OK\n";
				merge(u, v, k);
			}
		}
		else if(op == 2)
		{
			int u; cin >> u;
			ll k; cin >> k;
			
			if(find(u) == find(0))
			{
				if(d[u] != k) cout << "CONTRADICTION\n";
				else cout << "OK\n";
			}
			else
			{
				cout << "OK\n";
				merge(u, 0, k);
			}
		}
		else
		{
			int u, v; cin >> u >> v;
			if(find(u) == find(v)) cout << d[u] - d[v] << '\n';
			else cout << "UNKNOWN\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 1
// 3 5
// 1 1 2 5
// 1 2 3 7
// 3 1 3
// 1 3 1 -12
// 3 2 1

// OK
// OK
// 12
// OK
// -5


// 1
// 4 6
// 1 1 2 5
// 3 2 3
// 2 4 100
// 3 1 4
// 1 3 2 -7
// 3 1 3

// OK
// UNKNOWN
// OK
// UNKNOWN
// OK
// 12


// 1
// 2 4
// 2 1 10
// 1 1 2 3
// 2 2 8
// 3 2 1

// OK
// OK
// CONTRADICTION
// -3
