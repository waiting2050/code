#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//����˼·��������ŷ��������ֵm������m���������ӣ�ö��ÿһ�������Ƿ�������⣨��������ȡ��ģ�Ƿ����1�����ҵ���С���������
//ps������ŷ��������ֵ��һ�����������ģ�����һ������С�ģ���С��һ����������������������÷�֤��֤������ 

//ŷ�������ļ���������n���������ֽ⡣��n���������ֽ�ʽΪ��
//n =p^k*p2^k2*..��*p_m~k_m(���� p1, P2, ., P_m �ǻ�����ͬ��������k1, k2, ., k_m ��������)
//��ŷ�������Ĺ�ʽΪ��
//��(n) = n �� (1 - 1/p) �� (1 - 1/p2) �� ... �� (1 - 1/p_m)

//������ŷ������
ll phi(ll n)//ŷ������ֻ��n�й� 
{
	ll res = n;
	for(ll i = 2; i <= n / i; i++)//�������� 
	{
		if(n % i) continue;
		
		res = res / i * (i - 1);//��ÿһ��������ʹ�������ʽ 
		while(n % i == 0) n /= i;//�����Ѿ�ʹ�ù��������� 
	}
	if(n > 1) res = res / n * (n - 1);//��Ϊȱ����1��1���Ϸ��������Զ�Ӧ�ı���Ҳû���жϹ� 
	
	return res;
}

//������ģ�� 
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
