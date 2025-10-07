// Problem: Beautiful Sequence
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/118247/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 要求数组的gcd不存在于数组中的数量，不如反过来求（全部数量-gcd在数组中的数量）
// 既然要求gcd要在数组里，那么gcd=min(a1,a2,...,ai,...an)，对n个数，枚举其作为最小值时gcd贡献即可

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7, P = 998244353;

ll a[N], c[N];

ll qmi(ll a, ll b)
{
	a %= P;
	ll res = 1;
	while(b)
	{
		if(b & 1) res = res * a % P;
		
		a = a * a % P;
		b >>= 1;
	}
	
	return res;
}

ll mo(ll x) {return (x % P + P) % P;}

void solve()
{
	ll n; cin >> n;
	for(int i = 1; i <= n; i++) c[i] = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], c[a[i]]++;
	
	ll res = 0;
	for(int i = 1; i <= n; i++) // 这个时间复杂度是调和级数nlogn
	{
		ll cnt = 0;
		for(int j = i + i; j <= n; j += i) cnt += c[j];
		
		res += qmi(2ll, cnt) * mo(qmi(2ll, c[i]) - 1) % P; // 最小的基数是一定要的，所以减去空集，但是比他大的倍数不要也行
		res %= P;                                          
	}
	
	cout << mo(qmi(2ll, n) - 1 - res) << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 2
// 6
// 1 2 3 4 5 6
// 3
// 2 2 2
// 
// 22
// 0