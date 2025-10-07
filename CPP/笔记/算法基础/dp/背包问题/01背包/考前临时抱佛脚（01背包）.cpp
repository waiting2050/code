// Problem: 
//     P2392 kkksc03��ǰ��ʱ�����
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2392
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[5], dp[1207], mytime[21];
//����һ����ֻ������״̬��һ�Ǽӵ����ԣ����Ǽӵ����ԣ�������01����
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	for(int i = 1; i <= 4; i++) cin >> a[i];
	
	int ans = 0;
	for(int i = 1; i <= 4; i++)
	{
		int sum = 0;
		for(int j = 1; j <= a[i]; j++)
		{
			cin >> mytime[j];
			sum += mytime[j];
		}
		
		for(int j = 1; j <= a[i]; j++)
		{
			for(int k = sum >> 1; k >= mytime[j]; k--)
			{
				dp[k] = max(dp[k], dp[k - mytime[j]] + mytime[j]);//ʱ�䣨�������Ѵ��ۣ��ͼ�ֵ��һ���ģ����Լ�ȥmytie�ټ��� 
			}
		}
		ans += sum - dp[sum >> 1];//������һ����ʵ�ǵ�Ч�ģ���Ϊdp[sum>>1]һ��<=sum/2,����sum-dp�϶�>dp 
		//ans += max(dp[sum >> 1], sum - dp[sum >> 1]);//��Ϊʵ��ʱ�����ɻ��ѽ϶�Ĳ��־���������ȡ�� 
		
		memset(dp, 0, sizeof(dp));
	}
	
	cout << ans;
		
	return 0;
}

