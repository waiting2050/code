// Problem: Luogu P1438
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1438
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//原序列：0 0 0 0 0 0
//差分序列：0 0 0 0 0 0
//等差序列：1 3 5 7 9
//加上等差数列后的序列：1 3 5 7 9 0
//然后差分：1 2 2 2 2 -9

//可以得出结论：
//如果要在差分序列上加一个等差序列，则要在a[l]加上k，a[l+1]加上d，a[r+1]减去之前修改的总和 
//用线段树维护，求和（求第p个数）的时候求1~p的所有差分的和 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;

ll n, lz[N << 2], t[N << 2], a[N];

void pushup(int o)
{
	t[o] = t[o << 1] + t[o << 1 | 1];
}

void update(int s, int e, int o, int x)
{
	t[o] += (e - s + 1) * x;
	lz[o] += x;
}

void pushdown(int s, int e, int o)
{
	if(!lz[o]) return;
	
	int mid = (s + e) >> 1, ls = o << 1, rs = o << 1 | 1;
	update(s, mid, ls, lz[o]);
	update(mid + 1, e, rs, lz[o]);
	
	lz[o] = 0;//不要漏掉 
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
	if(l <= s && e <= r) return t[o];
	
	pushdown(s, e, o);
	
	int mid = (s + e) >> 1, res = 0;
	if(mid >= l) res += query(l, r, s, mid, o << 1);
	if(mid + 1 <= r) res += query(l, r, mid + 1, e, o << 1 | 1);
	
	return res;
}

void buildTree(int s = 1, int e = n, int o = 1)
{
	if(s == e)
	{
		t[o] = a[s];
		return;
	}
	
	int mid = (s + e) >> 1;
	buildTree(s, mid, o << 1), buildTree(mid + 1, e, o << 1 | 1);
	
	pushup(o);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = n; i >= 1; i--) a[i + 1] = a[i + 1] - a[i];
	
	buildTree();
	
	while(m--)
	{
		int op; cin >> op;
		if(op == 1)
		{
			int l, r, k, d; cin >> l >> r >> k >> d;
			add(l, l, k);
			if(l + 1 <= r) add(l + 1, r, d);
			if(r + 1 <= n) add(r + 1, r + 1, -(k + (r - l) * d));
		}
		else
		{
			int p; cin >> p;
			cout << query(1, p) << '\n';
		}
	}
	
	return 0;
}

//5 2
//1 2 3 4 5
//1 2 4 1 2
//2 3
//
//6
