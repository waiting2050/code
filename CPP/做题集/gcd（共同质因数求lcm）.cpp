#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 4e4 + 7, mod = 1e9 + 7;
bitset<N> vis;
int c[N];

void init()//����ɸ������ 
{
	int k = sqrt(N);
	for(int i = 2; i <= k; i++)
	{
		if(!vis[i])
			for(int j = i * i; j <= N; j += i) vis[j] = 1;
	}
}

void f(int x)//�ֽ�õ��������ݴ� 
{
	int k = sqrt(x);
	for(int i = 2; i <= k; i++)
	{
		if(x % i) continue;
		
		int cnt = 0;
		while(x % i == 0) cnt++, x /= i;
		c[i] = max(c[i], cnt);
	}
	
	if(x > 1) c[x] = max(c[x], 1);//��������������������û���ֽ� 
}

ll qmi(ll a, ll b)//������ 
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
		//��lcm�ĺ���˼�룺һ�����������ɸ��������ĳ˻����ɡ�
		//����2=2^1*3^0*5^0; 3=2^0*3^1*5^0; 5=2^0*3^0*5^1;��ôlcm(2,3,5)=2^1*3^1*5^1=30(Ҳ����ȡ�ݴ�������������ˣ� 
		if(!vis[i]) ans = ans * qmi(i, c[i]) % mod;
	}
	
	cout << ans;
	
	return 0;
}

//2 5
//
//60
