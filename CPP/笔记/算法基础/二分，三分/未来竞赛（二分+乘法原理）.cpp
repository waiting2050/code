#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

map<int, vector<int>> mp;//���ݿ��Ե�1e9����map�� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, d; cin >> n >> d;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		mp[x].push_back(i);//����xӵ�б��i��ѡ�֣�ע��i�Ǵ�С����ģ����ԵȻ᲻����sort�����ˣ� 
	}
	
	ll ans = 1;
	for(auto& [x, v] : mp)
	{
		ll temp = v.size() + 1;//��ѡ��ù����κ�һ��ѡ��Ҳ��һ�ַ��� 
		for(int i = 0; i < v.size(); i++)
		{
			//�ҵ���Ŵ��ڵ�ǰѡ����С�ڵ�ǰѡ��+d�ĸ�����ÿһ����������һ�ַ�������-1�ų��ұ߽磬-i��������߽�
			//�ظ������������ģ�����1,2,3,4,d=3:1+3=4,temp=1+2;2+3=5,temp=1+2+2��Ҳ����˵(1,2)(1,3)�����ַ�������(2,3)(2,4)�����ַ��� 
			ll add = upper_bound(v.begin(), v.end(), v[i] + d) - v.begin() - 1 - i;
			temp += add;
		}
		ans = (ans * temp) % MOD;
	}
	
	cout << ans - 1;//�ų�һ��ѡ�ֶ���ѡ�������ĳ�����ҵ�ѡ�ֿ���һ������ѡ�����ǲ������й��ҵ�ѡ�ֶ�һ����ѡ�� 
	
	return 0;
}

//5 2
//1 2 1 2 2 
//
//23
