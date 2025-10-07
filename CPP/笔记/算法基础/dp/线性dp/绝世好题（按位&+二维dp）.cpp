// Problem: Luogu P4310
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4310
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;

int a[N], b[32], dp[32][N];//dp[i][j]i��ʾ2���ݴη��ϵ�������1��31����j��ʾa[i]��dp��ʾ�ۻ�����ǰ�ĳ��� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= 31; i++) b[i] = 1 << (i - 1);//Ԥ����b������<=31��2ÿ���ݴ� 
	
	for(int i = 1; i <= n; i++)
	{
		int mx = 0;
		for(int j = 1; j <= 31; j++)//��ÿһ��a��������ÿһ������ת�ƹ�����·���������ҳ������������· 
		{
			//�����·��ָ���ǣ�����3=011��3���Դ�010��2����001��1��ת�ƣ���ô1��2����3��·����
			//������ԴӸ�·����������ô��¼���Ƚϵõ����ֵ 
			if(a[i] & b[j]) mx = max(mx, dp[j][i - 1]);//ע������i���У�j���� 
		}
		mx++;//�·������+1 
		for(int j = 1; j <= 31; j++)
		{
			if(a[i] & b[j]) dp[j][i] = mx;//�����ǰ�����·���ϣ��͸���Ϊmx 
			else dp[j][i] = dp[j][i - 1];//����ͼ̳�ǰһ�� 
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= 31; i++) ans = max(ans, dp[i][n]);
	
	cout << ans;
	
	return 0;
}

//3
//1 2 3
//
//2
//
//
//7
//13 16 9 12 4 4 18
//
//5
