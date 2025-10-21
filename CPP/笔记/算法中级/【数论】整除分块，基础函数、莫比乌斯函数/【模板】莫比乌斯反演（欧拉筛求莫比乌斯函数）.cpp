// 代码实现不难，思路比较难，详见.md文件

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 7;

ll mu[N];
bitset<N> vis;
vector<int> primes;

void init(int n)
{
	mu[1] = 1; // 这个一定要初始化，否则后面全错
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) primes.push_back(i), mu[i] = -1;
		for(int j = 0; j < primes.size() && 1ll * i * primes[j] <= n; j++)
		{
			vis[i * primes[j]] = 1;
			if(i % primes[j] == 0) 
			{
				mu[i * primes[j]] = 0;
				break;
			}
			mu[i * primes[j]] = -mu[i];			
		}
	}
	for(int i = 1; i <= n; i++) mu[i] += mu[i - 1];
}

void solve()
{
	int x, y, d; cin >> x >> y >> d;
	ll n = x / d, m = y / d;
	
	ll ans = 0;
	for(int l = 1, r = 1; l <= min(n, m); l = r + 1)
	{
		r = min({n, m, n / (n / l), m / (m / l)});
		ans += (n / l) * (m / l) * (mu[r] - mu[l - 1]);
	}
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	init(1e5);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 3
// 31 41 3
// 11 45 14
// 20 24 2
// 
// 86
// 0
// 76