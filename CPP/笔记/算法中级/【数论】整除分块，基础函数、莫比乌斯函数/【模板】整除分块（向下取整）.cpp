//整除分块通过将取值相同的连续区间合并计算，把形如∑ (i:1~n) ⌊n/i⌋的求和复杂度从O(n)降至O(√n)，高效处理

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

ll inv2 = inv(2); //防止inv(2)多次计算造成不必要的开销

void solve()
{
	ll n; cin >> n;
	
	ll ans = 0;
	for(ll l = 1, r = 1; l <= n; l = r + 1)
	{
        // k=⌊n/i⌋,k<=n/i =>i<=n/k 当k取l时，i最大为右边界r
		r = min(n, n / (n / l)); //n/l相当于k，即某一段区间共同的的值，选l作为代表，其实选l~r之间的别的数也可以
		ans = (ans + mo(n / l) * mo(l + r) % P * mo(r - l + 1) % P * inv2) % P;
        // n/l是整除分块的值，再用等差数列求和得到∑i的值，两者相乘得到答案
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

// 99
// 1686
// 424033111
// 
// 3
// 11
// 45
// 1145141919810