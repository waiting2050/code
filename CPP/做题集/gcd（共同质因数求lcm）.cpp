#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4e4 + 7, mod = 1e9 + 7;
bitset<N> vis;
int c[N];

void init()//埃氏筛求质数 
{
	int k = sqrt(N);
	for(int i = 2; i <= k; i++)
	{
		if(!vis[i])
			for(int j = i * i; j <= N; j += i) vis[j] = 1;
	}
}

void f(int x)//分解得到因数的幂次 
{
	int k = sqrt(x);
	for(int i = 2; i <= k; i++)
	{
		if(x % i) continue;
		
		int cnt = 0;
		while(x % i == 0) cnt++, x /= i;
		c[i] = max(c[i], cnt);
	}
	
	if(x > 1) c[x] = max(c[x], 1);//如果这个数本身是质数，没法分解 
}

ll qmi(ll a, ll b)//快速幂 
{
	ll res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;
		
		a = a * a % mod;
		b >>= 1;
	}
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int l, r; cin >> l >> r;
	init();
	
	for(int i = l; i <= r; i++) f(i);
	
	ll ans = 1;
	for(int i = 2; i <= r; i++)
	{
		//求lcm的核心思想：一个数由其若干个质因数的乘积构成。
		//比如2=2^1*3^0*5^0; 3=2^0*3^1*5^0; 5=2^0*3^0*5^1;那么lcm(2,3,5)=2^1*3^1*5^1=30(也就是取幂次最大的质因数相乘） 
		if(!vis[i]) ans = ans * qmi(i, c[i]) % mod;
	}
	
	cout << ans;
	
	return 0;
}

//2 5
//
//60
