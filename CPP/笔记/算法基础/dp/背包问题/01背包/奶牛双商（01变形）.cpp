// Problem: Luogu P2340
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2340
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 8e5 + 7, M = 8e5, DIF = 4e5;//N��������4e5����ֹ�±�Ϊ����ʱԽ�� 

int dp[N];//dp[i]��ʾ����Ϊiʱ�����̴�С 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	memset(dp, 128, sizeof(dp));
	dp[DIF] = 0;
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++)//01������ѡ��ѡ 
	{
		int s, f; cin >> s >> f;
		
		if(s >= 0)//���Ϊ������ô����һ�еĿ����ת�ƣ��������  
		{
			for(int j = M; j >= s; j--)
				dp[j] = max(dp[j], dp[j - s] + f);
		}
		else//����������� 
		{
			for(int j = 0; j <= M + s; j++)//��ֹԽ�磬s��ʱС��0 
				dp[j] = max(dp[j], dp[j - s] + f);
		}
	}
	
	int ans = -2e9;
	for(int i = DIF; i <= M; i++)
	//��i��dp[i]��ӣ�Ҳ���ǽ�������������� 
		if(dp[i] >= 0)
			ans = max(ans, dp[i] + i - DIF);//��ȥƫ������4e5�൱��ƫ�ƺ��0 
	
	cout << ans;
	
	return 0;
}

//5
//-5 7
//8 -6
//6 -3
//2 1
//-8 -5
//
//8
