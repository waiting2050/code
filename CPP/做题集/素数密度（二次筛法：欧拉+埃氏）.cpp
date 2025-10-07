// Problem: 
//     P1835 �����ܶ�
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

//����ŷ��ɸ��Ԥ�������r���������r��ͨ�õģ����ݷ�Χ����1e6Ҳ���ã����ڵ��������������ð���ɸ��ȥ���[l,r]��Χ�ڵĴ� 

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
	
	if(l == 1) l += 1;//����������� 
	if(l > r)
	{
		cout << '0';
		return 0;
	}
	
	euler(sqrt(r));
	
	for(int i = 0; i < primes.size(); i++)
	{
		ll x = primes[i];
		ll start = (l / x) * x;//��start��ʼ��Ϊx�ı������������ӽ�l 
		if(start < l) start += x;//ȷ��startһ����l����Ϊ�����ѭ���±���j-l����ֹԽ�� 
		if(start < 2 * x) start = 2 * x;//��Ϊxһ������Ŀ�귶Χ�ڣ�����������2x������ѭ������ 
		
		for(ll j = start; j <= r; j += x) ans[j - l] = 1;
	}
	
	ll cnt = 0;
	for(ll i = 0; i <= r - l; i++)//ע�ⷶΧ����Ϊans��r-l��Ϊ�±� 
		if(!ans[i]) cnt++;
		
	cout << cnt;
	
	return 0;
}

// 2 11
// 5
// 
// 10000 20000
// 1033
