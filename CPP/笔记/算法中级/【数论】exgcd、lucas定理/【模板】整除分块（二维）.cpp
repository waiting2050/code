#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int P = 1e9 + 7;

ll mo(ll x) {return (x % P + P) % P;}

void solve()
{
	ll n, m; cin >> n >> m;
	
    // 只需要在一维分块逻辑上增加分块即可，n与m分块可能重合或彼此独立，增加分块并单独计算每一个分块的值即可
	ll ans = 0;
	for(ll l = 1, r = 1; l <= n && l <= m; l = r + 1)
	{
		r = min({n, m, n / (n / l), m / (m / l)});
		ans = mo(ans + mo(n / l) * mo(m / l) % P * mo(r - l + 1));
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
// 114514 1919810
// 123 456
// 23333 15
// 
// 618396266
// 90765
// 533402