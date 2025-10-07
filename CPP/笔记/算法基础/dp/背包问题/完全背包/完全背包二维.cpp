#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ���峣����N����Ʒ���������ֵ��һЩ������M�Ǳ������������ֵ��һЩ����
const int N = 507, M = 1e5 + 7;

// w����洢ÿ����Ʒ�����������������v����洢ÿ����Ʒ�ļ�ֵ
int w[N], v[N];

// dp�������ڶ�̬�滮��dp[i][j]��ʾǰi����Ʒ������Ϊjʱ������ֵ
int dp[N][M];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> m >> n;
	
	for(int i = 1; i <= n; i++) 
		cin >> w[i] >> v[i]; // ע�������w��v�Ķ�������Ŀ�����෴��Ӧ����w[i]Ϊ������v[i]Ϊ��ֵ

	// ��̬�滮������
	for(int i = 1; i <= n; i++) // ����ÿ����Ʒ
	{
		for(int j = 0; j <= m; j++) // ����ÿ�ֿ��ܵ�������
		{
			if(j >= v[i]) // �����ǰ����j�㹻���µ�i����Ʒ
				dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]); // ��������ֵ
			else 
				dp[i][j] = dp[i - 1][j]; // ���򣬲�ѡ�����Ʒ������֮ǰ������ֵ
		}
	}

	cout << dp[n][m] << '\n';

	return 0;
}
