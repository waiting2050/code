// Problem: Luogu P1874
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1874
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 47, N = 1e5 + 7;

//������dp���ַ�ʽ��һά��ʾ��iΪֹ����ά��ʾĳ��״̬ 
int num[M][M], dp[M][N];//num[i][j]��i�ӵ�j�ĺͣ�dp[i][j]ǰiλ�ӵ�j�ļӺ�����

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string s; cin >> s;
	int n; cin >> n;
	
	int m = s.size();
	for(int i = 1; i <= m; i++)
	{
		for(int j = i; j <= m; j++)
		{
			num[i][j] = num[i][j - 1] * 10 + (s[j - 1] - '0');
			if(num[i][j] > n) num[i][j] = 0x3f3f3f3f;//�������Ҫ��һ������������Ϊ���ɴ����Ȼ����re��wa�� 
		}
	}
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = -1;//������ʼ��Ϊ0�����Ǳ���dp[1][num[1][1]]�ᱻdp[0][0]+1����Ϊ0.��Ϊ�����������м���ӼӺţ���dp�Ǹ�������ȥ��ƣ�����
	//num+num+num��+��num��1����˳�ʼ��Ϊ-1������������� 
	
	for(int i = 1; i <= m; i++)
	{
		for(int k = 0; k <= n; k++)
		{
			for(int j = 0; j < i; j++)
			{
				//�����ڱ���ģ�ͺ��Ӷλ��� 
				if(k >= num[j + 1][i]) dp[i][k] = min(dp[i][k], dp[j][k - num[j + 1][i]] + 1);
			}
		}
	}
	
	cout << (dp[m][n] >= 0x3f3f3f3f ? -1 : dp[m][n]);
	
	return 0;
}

// 99999
// 45
// 
// 4
