// Problem: Luogu P1541
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1541
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 350 + 7, M = 40 + 7;

//�����������е���һ���ᵽ���յ㣬����ֻ���ǳ���˳�򼴿ɣ�Ҳ���ǿ��ǵ�ǰ�غ�ѡ�����������Ƶ�����һ�� 
int dp[M][M][M][M], a[N], c[5];//dp[a][b][c][d]��ʾǰ����Ϊ1,2,3,4���Ʒֱ�����a,b,c,d�ţ�c���������ǰ����Ϊi������c[i]�� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++)
	{
		int x; cin >> x;
		c[x]++;
	}
	
	dp[0][0][0][0] = a[1];//һ���Ʋ��õķ�ֵΪa[1] 
	for(int i = 0; i <= c[1]; i++)
	{
		for(int j = 0; j <= c[2]; j++)
		{
			for(int u = 0; u <= c[3]; u++)
			{
				for(int v = 0; v <= c[4]; v++)
				{
					int t = i + j * 2 + u * 3 + v * 4 + 1;//����+1��ΪĬ�ϴ����1��ʼ��������0 
					if(i ^ 0) dp[i][j][u][v] = max(dp[i][j][u][v], dp[i - 1][j][u][v] + a[t]);
					if(j ^ 0) dp[i][j][u][v] = max(dp[i][j][u][v], dp[i][j - 1][u][v] + a[t]);
					if(u ^ 0) dp[i][j][u][v] = max(dp[i][j][u][v], dp[i][j][u - 1][v] + a[t]);
					if(v ^ 0) dp[i][j][u][v] = max(dp[i][j][u][v], dp[i][j][u][v - 1] + a[t]);
				}
			}
		}
	}
	
	cout << dp[c[1]][c[2]][c[3]][c[4]];//�ڹ�����ص����������е��Ƹպõ����յ� 
	
	return 0;
}

