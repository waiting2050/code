// Problem: 
//     P1835 素数密度
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1835
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//先用欧拉筛法预处理根号r（这个根号r是通用的，数据范围不在1e6也适用）以内的所有质数，再用埃氏筛法去标记[l,r]范围内的答案 

const int N = 1e5 + 7;
const int max_n = 1e6 + 7;
bitset<N> vis;
vector<ll> primes;
bitset<max_n> ans;

void euler(ll n)
{
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) primes.push_back(i);
		for(int j = 0; j < primes.size() && i * primes[j] <= n; j++)
		{
			vis[i * primes[j]] = 1;
			if(i % primes[j] == 0) break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll l, r; cin >> l >> r;
	
	if(l == 1) l += 1;//处理特殊情况 
	if(l > r)
	{
		cout << '0';
		return 0;
	}
	
	euler(sqrt(r));
	
	for(int i = 0; i < primes.size(); i++)
	{
		ll x = primes[i];
		ll start = (l / x) * x;//将start初始化为x的倍数，并尽量接近l 
		if(start < l) start += x;//确保start一定比l大，因为下面的循环下标是j-l，防止越界 
		if(start < 2 * x) start = 2 * x;//因为x一定不在目标范围内，所以起码是2x，减少循环次数 
		
		for(ll j = start; j <= r; j += x) ans[j - l] = 1;
	}
	
	ll cnt = 0;
	for(ll i = 0; i <= r - l; i++)//注意范围，因为ans将r-l作为下标 
		if(!ans[i]) cnt++;
		
	cout << cnt;
	
	return 0;
}

// 2 11
// 5
// 
// 10000 20000
// 1033
