// Problem: 子段异或
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120453/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 题目求a[l,r]=0的子段，看到区间异或和可以往前缀的方向去想。等式两边同时×a[1,l-1]，得a[1,l-1]^a[l,r]=a[1,l-1]
// 即a[1,l-1]=a[1,r]，与以前写的“k倍区间”的题目很像，类似同余定理，包括处理的细节（0的特判也一样）。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 200000 + 7;

int a[N], pre[N];

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) pre[i] ^= pre[i - 1] ^ a[i];
	
	unordered_map<int, ll> mp;
	for(int i = 1; i <= n; i++) mp[pre[i]]++;
	
	ll ans = 0;
	mp[0] += 1;
	for(auto& [k, v] : mp) ans += (v - 1) * v >> 1;
	
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 5
// 1 2 3 2 1

// 2