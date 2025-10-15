// i 的平方出现在哪些 f 中，比如 3 的平方出现在 f(3), f(6), f(9), f(12)…
// 求和式：∑(从i=1到n)f(i) = ∑(从i=1到n)i²×⌊n/i⌋
// 自然数幂和相关：
// 1⁰ + 2⁰ + 3⁰ + … + n⁰ = n
// 1 + 2 + 3 + … + n = (1 + n)×n / 2
// 1² + 2² + 3² + … + n² = n(n + 1)(2n + 1) / 6

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int P = 1e9 + 7;

ll mo(ll x) {return (x % P + P) % P;}

ll qmi(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1) res = res * a % P;
		a = a * a % P;
		b >>= 1;
	}
	
	return res;
}

ll inv(ll x) {return qmi(x, P - 2);}
ll inv6 = inv(6);

ll f(ll x) // f(r)-f(l-1)，类似前缀和，通过自然数幂和+前缀性质快速求区间平方和
{
	x %= P;
	return x * (x + 1) % P * (2 * x + 1) % P * inv6 % P;
}

void solve()
{
	ll n; cin >> n;
	
	ll ans = 0;
	for(ll l = 1, r = 1; l <= n; l = r + 1)
	{
		r = min(n, n / (n / l));
		ans = mo(ans + (n / l) * mo(f(r) - f(l - 1)));
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

// 4
// 12
// 23
// 45
// 123456
// 
// 801
// 5115
// 37736
// 757760216