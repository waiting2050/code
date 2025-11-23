// Problem: AT ABC433 F
// Contest: AtCoder - AtCoder Beginner Contest 433AtCoder 初学者竞赛 433
// URL: https://atcoder.jp/contests/abc433/tasks/abc433_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 思路其实很简单，假设字串长度为2k，先找到断点idx，即该点为左集合最后一个数字，然后在idx左边找k-1个相同的数，再在右边找
// k个数，使得value[idx]+1为右集合数的值，答案为c(l, k-1)*c(r, k)，但是这样子要枚举k，可能超时，这时可以用范德蒙德卷积优化
// c(r, k)=c(r, r-k)，c(l, k-1)*c(r, r-k)=c(l+r,r-1)，将上面/下面的数分别相加，于是将单次操作优化为了O(1)
// oiwiki(范德蒙德卷积):https://oi-wiki.org/math/combinatorics/vandermonde-convolution/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 1e6 + 7, P = 998244353, MX = 10;

// pc即pre_cnt，tc即total_cnt，用tc-pc即suffix_cnt
ll f[N], invf[N], pc[MX], tc[MX];

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

ll inv(ll x) {return qmi(x, P - 2);}

void init()
{
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = (f[i - 1] * i) % P;
	invf[N - 1] = inv(f[N - 1]);
	for(int i = N - 2; i >= 0; i--) invf[i] = (invf[i + 1] * (i + 1)) % P;
}

ll c(ll n, ll m)
{
	if(n < 0 || m < 0 || m > n) return 0;
	return f[n] * invf[m] % P * invf[n - m] % P;
}

void solve()
{
	string s; cin >> s;
	int n = s.size();
	s = "?" + s;
	
	for(int i = 1; i <= n; i++) tc[s[i] - '0']++;
	
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int cur = s[i] - '0';
		if(cur == 9)
		{
			pc[cur]++; // 注意这一步不能漏
			continue;
		}
		
		int nc = cur + 1;
		int l = pc[cur], r = tc[nc] - pc[nc];
		ans = (ans + c(l + r, r - 1)) % P;
		
		pc[cur]++;
	}
	
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	init();
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 1122

// 5


// 2025

// 0


// 0777468889971

// 30