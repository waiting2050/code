// Problem: 二小姐的区间查询
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/119225/F
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7, B = 495;

int t[N << 2][15];

int a[N], g[15], h[500], n, c[15];

void pushup(int o)
{
	for(int i = 1; i <= 12; i++)
		t[o][i] = t[o << 1][i] + t[o << 1 | 1][i];
}

void buildTree(int s = 1, int e = n, int o = 1)
{
	if(s == e)
	{
		t[o][h[a[s]]] = 1;
		return;
	}
	
	int mid = (e + s) >> 1;
	buildTree(s, mid, o << 1);
	buildTree(mid + 1, e, o << 1 | 1);
	
	pushup(o);
}

void update(int k, int pre, int nxt, int s = 1, int e = n, int o = 1)
{
	if(s == e)
	{
		t[o][h[pre]]--;
		t[o][h[nxt]]++;
		return;
	}
	
	int mid = (s + e) >> 1;
	if(k <= mid) update(k, pre, nxt, s, mid, o << 1);
	else update(k, pre, nxt, mid + 1, e, o << 1 | 1);
	
	pushup(o);
}

void query(int l, int r, int s = 1, int e = n, int o = 1)
{
	if(l <= s && e <= r)
	{
		for(int i = 1; i <= 12; i++) c[i] += t[o][i];
		return;
	}
	
	int mid = (s + e) >> 1;
	if(mid >= l) query(l, r, s, mid, o << 1);
	if(mid + 1 <= r) query(l, r, mid + 1, e, o << 1 | 1);
}

void solve()
{
	int q; cin >> n >> q;
	
	int idx = 0;
	for(int i = 1; i <= B; i++)
	{
		if(B % i) continue;
		
		g[++idx] = i;
		h[i] = idx;
	}
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] = __gcd(a[i], B);
	}
	buildTree();
	
	while(q--)
	{
		int op; cin >> op;
		
		if(op == 1)
		{
			int x, y; cin >> x >> y;
			int nxt = __gcd(y, B);
			update(x, a[x], nxt);
			a[x] = nxt;
		}
		else
		{
			int l, r; cin >> l >> r;
			for(int i = 1; i <= 12; i++) c[i] = 0;
			query(l, r);
			
			ll ans = 0;
			for(int i = 1; i <= 12; i++)
			{
				for(int j = i; j <= 12; j++)
				{
					if(g[i] * g[j] % B) continue;
					
					if(i == j) ans += 1ll * c[i] * (c[i] - 1ll) >> 1;
					else ans += 1ll * c[i] * c[j];
				}
			}
			
			cout << ans << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 5 3
// 1 1 1 1 495
// 2 1 5
// 1 1 495
// 2 1 5

// 4
// 7