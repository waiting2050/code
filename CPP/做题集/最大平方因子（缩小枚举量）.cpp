#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//本来x最大到1e18，枚举a要到1e9,枚举b要1e18，肯定都会超时，但如果先枚举1~1e6的b，再枚举1~1e6的a，
//那么刚刚好可以凑齐全部的1e18的数据，但是只要跑2e6次 

void solve()
{
	ll x; cin >> x;
	for(int i = 1; i <= 1e6; i++)
	{
		if(x % i) continue;
		
		ll a = sqrt(x / i);
		if(a * a * i == x)
		{
			cout << a << '\n';
			return;
		}
	}
	for(int i = 1e6; i >= 1; i--)
	{
		if(x % i % i) continue;
		
		ll b = x / i / i;
		if(b * i * i == x)
		{
			cout << i << '\n';
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

// 3
// 75
// 1800
// 1005
// 
// 5
// 30
// 1

