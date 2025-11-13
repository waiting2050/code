// Problem: Enjoy the game
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120454/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 枚举前几个n，发现n=2,4,8...时必输，而1,3,5,6,7,9,10...是必赢的，于是猜想当n为2的幂次时必输。此时，先手选x个，
// （首先x肯定<n/2，否则后手直接能拿完），后手拿x'个，使n-x-x'依旧为2的幂次，这样先手始终是必输态

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define eb emplace_back

void solve()
{
	ll n; cin >> n;
	cout << (n & (n - 1) ? "Bob" : "Alice");
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 2

// Alice