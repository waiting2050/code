/*
Lucas�����������ȡģ������
https://www.starrycoding.com/problem/125
����ȡģ����С��ʱ����Ҫ�������������׳�Ϊ 0 ���� 0 / 0
ʱ�临�Ӷ� O(p + logp) = O(p)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e5 + 7;

ll f[N], invf[N];

ll qmi(ll x, ll b, ll p)
{
	x %= p;
	
	ll res = 1;
	while(b)
	{
		if(b & 1) res = res * x % p;
		x = x * x % p;
		b >>= 1;
	}
	
	return res;
}

ll inv(ll x, ll p) {return qmi(x, p - 2, p);}

ll c(ll n, ll m, ll p) 
{
	if(n < m || m < 0) return 0;
	return f[n] * invf[m] % p * invf[n - m] % p;
}

ll lucas(ll n, ll m, ll p) //���������ɳ������ֺ��������� 
{
	if(m == 0) return 1;
	return lucas(n / p, m / p, p) * c(n % p, m % p, p) % p;
}

void solve()
{
	ll n, m, p; cin >> n >> m >> p;
	
	f[0] = 1, invf[0] = 1;
	for(int i = 1; i <= p - 1; i++) f[i] = f[i - 1] * i % p;
	invf[p - 1] = inv(f[p - 1], p); //�������ֵĵ����Ƿ����
	for(int i = p - 2; i >= 1; i--) invf[i] = invf[i + 1] * (i + 1) % p;
	
	cout << lucas(n + m, min(n, m), p) << '\n';
}
	
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

// 4
// 2 5 7
// 3 9 17
// 2 1 5
// 11 45 13
// 
// 0
// 16
// 3
// 0
