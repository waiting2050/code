#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//本题思路就是先求欧拉函数的值m，再找m的所有因子，枚举每一个因子是否符合题意（即快速幂取完模是否等于1），找到最小的因子输出
//ps；首先欧拉函数的值是一定符合条件的，但不一定是最小的；最小的一定在其因子里产生（可以用反证法证明）。 

//欧拉函数的计算依赖于n的质因数分解。若n的质因数分解式为：
//n =p^k*p2^k2*..。*p_m~k_m(其中 p1, P2, ., P_m 是互不相同的质数，k1, k2, ., k_m 是正整数)
//则欧拉函数的公式为：
//Φ(n) = n × (1 - 1/p) × (1 - 1/p2) × ... × (1 - 1/p_m)

//用来求欧拉函数
ll phi(ll n)//欧拉函数只和n有关 
{
	ll res = n;
	for(ll i = 2; i <= n / i; i++)//求质因子 
	{
		if(n % i) continue;
		
		res = res / i * (i - 1);//对每一个质因子使用这个公式 
		while(n % i == 0) n /= i;//消除已经使用过的质因子 
	}
	if(n > 1) res = res / n * (n - 1);//因为缺少了1（1不合法），所以对应的本身也没有判断过 
	
	return res;
}

//快速幂模板 
ll qmi(ll a, ll b, ll c)
{
	a %= c;
	ll res = 1;
	while(b)
	{
		if(b & 1) res = res * a % c;
			
		a = a * a % c;
		b >>= 1;
	}
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll a, n; cin >> a >> n;
	
	ll m = phi(n), ans = m;
	for(ll i = 1; i <= m / i; i++)
	{
		if(m % i) continue; 
		
		if(qmi(a, i, n) == 1) ans = min(ans, i);
		ll j = m / i;
		if(i != j && qmi(a, j, n) == 1) ans = min(ans, j);
	}
	
	cout << ans;
	
	return 0;
}

// 10 101
// 
// 4
