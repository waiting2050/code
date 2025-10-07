#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

//ŷ�����ݣ� 
//��� a �� p ���ʣ�a^b �� a^(b mod ��(p)) mod p
//��� a �� p �������� b �� ��(p)��a^b �� a^(b mod ��(p) + ��(p)) mod p
//��� a �� p �������� b < ��(p)��ֱ�Ӽ��� a^b mod p

ll phi(ll p)
{
	ll res = p;
	for(int i = 2; i <= p / i; i++)
	{
		if(p % i) continue;
		
		res = res / i * (i - 1);
		while(p % i == 0) p /= i;
	}
	if(p > 1) res = res / p * (p - 1);
	
	return res;
}

ll qmi(ll a, ll b, ll p)
{
	ll res = 1;
	a %= p;
	while(b)
	{
		if(b & 1) res = res * a % p;
		
		a = a * a % p;
		b >>= 1;
	}
	
	return  res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll a, p;
	string b; cin >> a >> b >> p;
	
	ll ph = phi(p), res = 0;
	for(auto& y : b) res = (res * 10 + y - '0') % ph; //�ؾ���ȡģ
	
	cout << qmi(a, res, p);
	
	return 0;
}

// 114 514 191
// 
// 138
