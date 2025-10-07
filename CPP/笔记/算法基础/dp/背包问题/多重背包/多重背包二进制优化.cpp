#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 7;
ll dp[N];	// ��̬�滮�����ڴ洢ÿ�������µ�����ֵ

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m, n; // �ֱ�������������������Ʒ������
	cin >> m >> n;
	
	// ����ÿһ����Ʒ
	for(int i = 1; i <= n; i++)
	{
		int s, w, v; // �ֱ����ǰ��Ʒ����������ֵ�����
		cin >> s >> w >> v;
		
		vector<ll> vec;
		ll x = 1;
		while(s >= x) vec.push_back(x), s -= x, x <<= 1;
		if(s) vec.push_back(s);
		for(auto &ele: vec)
			// ��������ӱ����������������ǰ��Ʒ�ļ�ֵ
			for(int j = m; j >= ele * v; j--)
				// ȷ����ǰ�����������ɸ���Ʒ�������¶�̬�滮��
					dp[j] = max(dp[j], dp[j - ele * v] + ele * w); // ����Ϊ�������Ʒ�������ֵ
  	}
  	
  	  	cout << dp[m];
  	
  	return 0;
}
