#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll exgcd(ll a, ll b, ll& x, ll& y)
{
	if(!b) return x = 1, y = 0, a;
	ll d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	
	return d;
}

ll mo(ll x, ll p) {return (x % p + p) % p;}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll a, b, c; cin >> a >> b >> c;
	ll x, y, d = exgcd(abs(a), abs(b), x, y);
	
	if(c % d) cout << -1 << '\n'; //有解的话c是d的倍数 
	else
	{
		if(a < 0) x = -x;
		x = mo(x * (c / d), b / d); //b/d相当于步长，即解与解之间的间隔
									//方程的一般解可以表示为：x0+t*(b/d)，取模相当于找最小；而x0*(c/d)是一个特解 
		
		cout << x << '\n';
	}
	
	return 0;
}

// 3 9 7
// 
// -1
// 
// 
// -2 8 -2
// 
// 1
