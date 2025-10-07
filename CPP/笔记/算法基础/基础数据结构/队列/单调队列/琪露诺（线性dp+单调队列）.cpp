// Problem: Luogu P1725
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1725
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int dp[N], a[N], dq[N];//dp��ʾ��i��λ�õ����ħ��ֵ 

//��ÿ��λ�ã��������ƶ���[i+l,i+r]�����൱��ÿ��i�����Դ�[i-r,i-l]��������ֵת�ƹ����������������ܻ�ﵽ1e10���Ӷ� 
//���ǵ���ĳ���̶���������ֵת�ƹ���������ʹ�õ������� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, l, r; cin >> n >> l >> r;
	for(int i = 0; i <= n; i++) cin >> a[i];
	
	memset(dp, 128, sizeof(dp));//��Ϊ����ֵ�����и��ģ����Գ�ʼ��Ϊ�ܴ�ĸ�ֵ(char��[0,255],��ֵ0~127����ʼ��128ֱ�����Ϊ���ĸ�ֵ) 
	dp[0] = 0;
	
	//�ѵ���������޶�ת����[i-r,i-l]������� 
	int hh = 1, tt = 0, ans = -2e9;
	for(int i = l; i <= n; i++)//ע���l��ʼ 
	{
		while(tt >= hh && dq[hh] < i - r) hh++;
		while(tt >= hh && dp[dq[tt]] <= dp[i - l]) tt--;
		
		dq[++tt] = i - l;//ע����������i-l����������[n-l+1,n]�ǲ�����ӵġ�ͨ�����������<=i-l�ķ�Χ�� 
		dp[i] = dp[dq[hh]] + a[i];
		
		if(i + r > n) ans = max(ans, dp[i]);
	}
	
	cout << ans;
	
	return 0;
}

//5 2 3
//0 12 3 11 7 -2
//
//11
