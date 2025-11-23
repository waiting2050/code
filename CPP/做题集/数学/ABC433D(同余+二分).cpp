// Problem: AT ABC433 D
// Contest: AtCoder - AtCoder Beginner Contest 433AtCoder 初学者竞赛 433
// URL: https://atcoder.jp/contests/abc433/tasks/abc433_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 根据f函数的定义，设前后的两个数分别是x,y，那么题目要求x*10^len(y)+y % M = 0,移项得 y % M = -x*10^len(y) % M
// 设a=-x*10^len(y) % M，那么当a=y%M时，答案计数+1。但是要注意a会被len(y)所约束，所以a要找对应len下的y去配对
// 同时注意a是负数，对负数取模。将y处理后放入对应长度数组并排序，查找时根据单调性用二分查找对应的y即可。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 2e5 + 7, ML = 11; // max_len

int m;
ll a[N], tp[ML]; // tp即ten_pow

int mo(ll x) {return (x % m + m) % m;}

void solve()
{
	int n; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll base = 1;
	for(int i = 0; i <= 10; i++) tp[i] = base, base *= 10;
	
	vector<ll> g[ML];
	for(int i = 1; i <= n; i++)
	{
		int len = log10(a[i]) + 1;
		g[len].pb(a[i] % m);
	}
	for(int i = 0; i < ML; i++) sort(g[i].begin(), g[i].end());
	
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ll v = a[i] % m; // long long最大到9e18，因此提前取模防止溢出
		for(int j = 0; j < ML; j++)
		{
			ll t = v * tp[j] * -1;
			int target = mo(t);
			
			auto st = lower_bound(g[j].begin(), g[j].end(), target);
			auto ed = upper_bound(g[j].begin(), g[j].end(), target);
			ans += ed - st;
		}
	}
	
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 2 11
// 2 42

// 2


// 4 7
// 2 8 16 183

// 4


// 5 5
// 1000000000 1000000000 1000000000 1000000000 1000000000

// 25


// 12 13
// 80 68 862370 82217 8 56 5 168 672624 6 286057 11864

// 10