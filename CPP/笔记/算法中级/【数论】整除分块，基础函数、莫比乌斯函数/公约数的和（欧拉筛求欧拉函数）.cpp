#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e6 + 7, P = 1e9 + 7;

bitset<N> vis;
vector<int> primes;
ll phi[N];
ll pre[N];

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

ll inv(ll a) {return qmi(a, P - 2);}
ll inv2 = inv(2);

void init(int n)
{
	vis[0] = vis[1] = 1;
	phi[1] = 1; // 这里一定要初始化，否则全错
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) primes.push_back(i), phi[i] = i - 1;
		for(int j = 0; j < primes.size() && 1ll * i * primes[j] <= n; j++)
		{
			vis[i * primes[j]] = 1;
			if(i % primes[j] == 0)
			{
				phi[i * primes[j]] = phi[i] * primes[j];
				break;
			}
			phi[i * primes[j]] = phi[i] * phi[primes[j]];
		}
	}
	for(int i = 1; i <= n; i++) pre[i] = (pre[i - 1] + phi[i]) % P;
}

void solve()
{
	ll n; cin >> n;
	
	ll ans = 0;
	for(int l = 1, r = 1; l <= n; l = r + 1)
	{
		r = min(n, n / (n / l));
		ans = mo(ans + mo(pre[r] - pre[l - 1]) * (n / l) % P * (n / l) % P);
	}
	ans = mo(mo(ans - (1ll + n) * n % P * inv2 % P) * inv2);
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	init(1e6);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 3
// 81
// 19
// 1234
// 
// 8100
// 283
// 3101733