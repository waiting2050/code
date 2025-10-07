// Problem: Luogu P3205
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3205
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//���� dp ��һ�����ʡ������������С���䣬�����ͷ���������һ������:

const int N = 1e3 + 7, P = 19650827;

int dp[N][N][2], a[N];//dp[i][j][0]��ʾ�ӵ�i���˵���j������ɵ��Ӷ��У���i���˴���߲�����ܵ��������1���ʾj���ұ߲��룩 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) dp[i][i][0] = 1;//�����ٳ�ʼ��dp[i][i][1]��������ظ�������
	//��֮���״̬ת��Ҳ���Կ����µ�dp����ǰ����״̬(����ά�ֱ���0,1)ת��
	
	for(int len = 1; len <= n; len++)//���䳤 
	{
		for(int i = 1, j = i + len - 1; j <= n; i++, j++)//���Ҷ˵� 
		{
			//��ʵ�޷Ǿ�����ת�ƣ��µ�����ھɵ���/�ң��µ��Ҳ��ھɵ���/�� 
			if(a[i] < a[i + 1]) dp[i][j][0] += dp[i + 1][j][0];
			if(a[i] < a[j]) dp[i][j][0] += dp[i + 1][j][1];
			if(a[j] > a[i]) dp[i][j][1] += dp[i][j - 1][0];
			if(a[j] > a[j - 1]) dp[i][j][1] += dp[i][j - 1][1];
			dp[i][j][0] %= P, dp[i][j][1] %= P;
		}
	}
	
	cout << (dp[1][n][0] + dp[1][n][1]) % P;
	
	return 0;
}

// 4
// 1701 1702 1703 1704
// 
// 8
