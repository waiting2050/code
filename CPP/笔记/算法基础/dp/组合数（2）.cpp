#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e7 + 3;
const int mod = 1e9 + 7;

ll fac[N];

ll qmi(ll a, ll b)
{
	ll res = 1ll;
	while(b)
	{
		if(b & 1) res = res * a % mod;
		
		a = a * a % mod;
		b >>= 1;
	}
	
	return res;
}

ll inv(ll x) {return qmi(x, mod - 2);}

void init(int n)	//³õÊ¼»¯¼ÆËã½×³Ë
{
	fac[0] = 1;
	for(int i = 1; i < n; i++) fac[i] = fac[i - 1] * i % mod;
}

ll c(ll n, ll m)
{
	if(n < 0 || m < 0 || n < m) return 0;
	
	return fac[n] * inv(fac[n - m] * fac[m] % mod) % mod;
}

void solve()
{
	int n, m;cin >> n >> m;
	cout << c(n, m) << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	init(N);
	
	int q;cin >> q;
	while(q--) solve();
	
	return 0;
}

// 3
// 5 3
// 7 5
// 3 3
// 
// 10
// 21
// 1
