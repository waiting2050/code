#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;
int dp[N];	// ��̬�滮�����ڴ洢ÿ�������µ�����ֵ

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m, n; // �ֱ�������������������Ʒ������
	cin >> m >> n;
	
	// ����ÿһ����Ʒ //��������ѭ����ʱ�临�ӶȽϸ� 
	for(int i = 1; i <= n; i++)
	{
		int s, w, v; // �ֱ����ǰ��Ʒ����������ֵ�����
		cin >> s >> w >> v;
		
		// ����ÿ����Ʒ����������������ѭ������
		while(s--)
			// ��������ӱ����������������ǰ��Ʒ�ļ�ֵ
			for(int j = m; j >= v; j--)
				// ȷ����ǰ�����������ɸ���Ʒ�������¶�̬�滮��
				if(j >= v) 
					dp[j] = max(dp[j], dp[j - v] + w); // ����Ϊ�������Ʒ�������ֵ
  	}
  	
  	  	cout << dp[m];
  	
  	return 0;
}
