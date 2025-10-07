// Problem: CF 2134 B
// Contest: Codeforces - Codeforces Round 1045 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2134/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

//对x而言，每次加上k再%(k+1)相当于-1，设a=n*(k+1)+r,那么一定有r<=k，至多操作k次可以消除余数的影响（刚好满足题意）
//所以对ai，设法消除其余数的影响即可

void solve()
{
	ll n, k; cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		cout << x + x % (k + 1) * k << ' ';
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

// 8
// 3 3
// 2 7 1
// 4 5
// 2 9 16 14
// 4 1
// 1 2 3 4
// 5 2
// 5 6 7 8 9
// 2 10
// 7 9
// 1 1000000000
// 1
// 1 371
// 1000000000
// 3 6
// 1 3 5
// 
// 8 10 10
// 7 14 21 14
// 2 2 4 4
// 9 6 9 12 9
// 77 99
// 1000000000000000001
// 1000000000
// 25 15 5