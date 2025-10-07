#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//����x���1e18��ö��aҪ��1e9,ö��bҪ1e18���϶����ᳬʱ���������ö��1~1e6��b����ö��1~1e6��a��
//��ô�ոպÿ��Դ���ȫ����1e18�����ݣ�����ֻҪ��2e6�� 

void solve()
{
	ll x; cin >> x;
	for(int i = 1; i <= 1e6; i++)
	{
		if(x % i) continue;
		
		ll a = sqrt(x / i);
		if(a * a * i == x)
		{
			cout << a << '\n';
			return;
		}
	}
	for(int i = 1e6; i >= 1; i--)
	{
		if(x % i % i) continue;
		
		ll b = x / i / i;
		if(b * i * i == x)
		{
			cout << i << '\n';
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while(t--) solve();
	
	return 0;
}

// 3
// 75
// 1800
// 1005
// 
// 5
// 30
// 1

