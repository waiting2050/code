#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int P = 1e9 + 7;

ll mo(ll x) {return (x % P + P) % P;}

ll qmi(ll a, ll b)
{
	ll res = 1;
	a %= P;
	while(b)
	{
		if(b & 1) res = res * a % P;
		a = a * a % P;
		b >>= 1;
	}
	
	return res;
}

ll inv(ll x) {return qmi(x, P - 2);}

ll inv2 = inv(2);

// ⌈n/i⌉=k ≥ n/i > k−1
// n/k <= i < n/(k-1)
// i≤⌊(n-1)/(k-1)⌋，特判 k=1时，r=n
ll getr(ll n, ll l)
{
	ll k = (n + l - 1) / l;
	if(k == 1) return n;
	return (n - 1) / (k - 1);
}

void solve()
{
	ll n; cin >> n;
	
	ll ans = 0;
	for(ll l = 1, r = 1; l <= n; l = r + 1)
	{
        //与向下取整比起来只需要将r的更新规则修改，并将值k改成向上取整即可
		r = min(n, getr(n, l));
		ans = (ans + mo((n + l - 1) / l) * mo(l + r) % P * mo(r - l + 1) % P * inv2) % P;
	}
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 3
// 123
// 456
// 1145141919810
// 
// 19918
// 274424
// 454143119