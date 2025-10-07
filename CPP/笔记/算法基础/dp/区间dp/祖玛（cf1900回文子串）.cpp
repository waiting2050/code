// Problem: Luogu CF607B
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF607B
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 500 + 7;

int a[N], dp[N][N];//��������[i,j]����С����

//״̬ת�Ʒ����Ƿǳ���ͨ������dp�����Ǽ����˻��ĵ���������Ҫ����ĸ��࿼�� 
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= n; i++) dp[i][i] = 1;//����Ϊ1�Ĵ���Ȼ�ǻ��Ĵ�
	for(int i = 1; i < n; i++) dp[i][i + 1] = dp[i][i] + (a[i] != a[i + 1]);//����Ϊ2�Ļ��Ĵ���Ҫ�ر��ʼ�� 
	
	for(int len = 3; len <= n; len++)//����Ϊ1��2�Ѿ���ʼ����ɣ��ӳ���3��ʼ 
	{
		for(int i = 1, j = i + len - 1; j <= n; i++, j++)
		{
			//�����Ҷ˵���ȣ����������ڵ�����������кܶ�������Ļ����Ӵ���
			//һ������ĳ�������Ӵ�������������Ӵ������Ժ�ʣ�µ��Ǹ������ټ����������˵� 
			if(a[i] == a[j]) dp[i][j] = dp[i + 1][j - 1];
			for(int k = i; k < j; k++) 	dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
		}
	}
	
	cout << dp[1][n];
	
	return 0;
}

//3
//1 2 1
//
//1
//
//
//3
//1 2 3
//
//3
//
//
//7
//1 4 4 2 3 2 1
//
//2
