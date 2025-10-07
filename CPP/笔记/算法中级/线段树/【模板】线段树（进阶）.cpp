#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int n;
ll a[N], add[N << 2], mul[N << 2], t[N << 2];
const ll P = 998244353;

ll mo(ll x) {return (x % P + P) % P;}

void pushup(int o)
{
	t[o] = mo(t[o << 1] + t[o << 1 | 1]);
}

//实际值: mul[o] * y + add[o]
//    -> (mul[o] * y + add[o]) * k + x
//    -> mul[o] * y * k + add[o] * k + x;
//所以更新: mul[o] = mul[o] * k , add[o] = add[o] * k + x
void update(int s, int e, int o, ll k, ll x)
{
	t[o] = mo(mo(t[o] * k) + mo(x * (ll)(e - s + 1)));
	add[o] = mo(mo(add[o] * k) + x);
	mul[o] = mo(mul[o] * k);
}

void pushdown(int s, int e, int o)
{
	int mid = (s + e) >> 1, ls = o << 1, rs = o << 1 | 1;
	
	update(s, mid, ls, mul[o], add[o]);
	update(mid + 1, e, rs, mul[o], add[o]);
	
	mul[o] = 1;
	add[o] = 0;
}

void modify(int l, int r, ll k, ll x, int s = 1, int e = n, int o = 1)
{
	if(l <= s && e <= r)
	{
		update(s, e, o, k, x);
		return;
	}
	
	pushdown(s, e, o);
	
	int mid = (s + e) >> 1;
	if(mid >= l) modify(l, r, k, x, s, mid, o << 1);
	if(mid + 1 <= r) modify(l, r, k, x, mid + 1, e, o << 1 | 1);
	
	pushup(o);
}

ll query(int l, int r, int s = 1, int e = n, int o = 1)
{
	if(l <= s && e <= r) return t[o];
	
	pushdown(s, e, o);
	
	ll res = 0;
	int mid = (s + e) >> 1;
	if(mid >= l) res = mo(res + query(l, r, s, mid, o << 1));
	if(mid + 1 <= r) res = mo(res + query(l, r, mid + 1, e, o << 1 | 1));
	
	return res;
}

void buildTree(int s = 1, int e = n, int o = 1)
{
	mul[o] = 1;
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
	
	int q; cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	buildTree();
	
	while(q--)
	{
		int op, l, r; cin >> op >> l >> r;
		
		if(op == 1)
		{
			ll x; cin >> x;
			modify(l, r, 1, x);
		}
		else if(op == 2)
		{
			ll x; cin >> x;
			modify(l, r, x, 0);
		}
		else if(op == 3)
		{
			ll x; cin >> x;
			modify(l, r, 0, x);
		}
		else
		{
			cout << query(l, r) << '\n';
		}
	}
	
	return 0;
}

//5 5
//1 2 3 4 5
//1 1 3 2
//2 1 3 3
//4 1 2
//3 4 5 7
//4 1 5
//
//21
//50
