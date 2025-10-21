// 计算 sum(k % i for i in 1..n)
// 推导过程：
// 1. 取模运算的定义：a % b = a - ⌊a/b⌋×b
// 2. 对每个 i 从 1 到 n，k % i = k - ⌊k/i⌋×i
// 3. 求和：sum(k % i) = sum(k - ⌊k/i⌋×i) （i 从 1 到 n）
// 4. 拆分求和式：sum(k) - sum(⌊k/i⌋×i) （i 从 1 到 n）
// 5. sum(k) 共 n 项，所以 sum(k) = n * k
// 最终：sum(k % i) = n * k - sum(⌊k/i⌋×i for i in 1..n)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int P = 1e9 + 7;

ll qmi(ll a, ll b)
{
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
ll inv2 = inv(2);

ll mo(ll x) {return (x % P + P) % P;}

void solve()
{
	ll n, k; cin >> n >> k;
	
	ll ans = n % P * k % P;
	for(ll l = 1, r = 1; l <= min(n, k); l = r + 1)
	{
		r = min(n, k / (k / l));
		ans = mo(ans - k / l * (l + r) % P * (r - l + 1) % P * inv2 % P) % P;
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
// 123456 123456
// 234 888
// 1145 888
// 
// 705728397
// 13603
// 367594