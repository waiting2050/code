#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ���峣����N����Ʒ���������ֵ��һЩ������M�Ǳ������������ֵ��һЩ����
const int N = 507, M = 1e5 + 7;

// w����洢ÿ����Ʒ�����������������v����洢ÿ����Ʒ�ļ�ֵ
int w[N], v[N];

// dp�������ڶ�̬�滮��dp[i][j]��ʾǰi����Ʒ������Ϊjʱ������ֵ
int dp[2][M];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> m >> n;
	
	for(int i = 1; i <= n; i++) 
		cin >> w[i] >> v[i]; // ע�������w��v�Ķ�������Ŀ�����෴��Ӧ����w[i]Ϊ������v[i]Ϊ��ֵ

	// ��̬�滮������
	for(int i = 1; i <= n; i++) // ����ÿ����Ʒ
	{
		int y = i & 1;
		for(int j = 0; j <= m; j++) // ����ÿ�ֿ��ܵ�������
		{
			if(j >= v[i]) // �����ǰ����j�㹻���µ�i����Ʒ
				dp[y][j] = max(dp[y ^ 1][j], dp[y][j - v[i]] + w[i]); // ��������ֵ
			else 
				dp[y][j] = dp[y ^ 1][j]; // ���򣬲�ѡ�����Ʒ������֮ǰ������ֵ
		}
	}

	cout << dp[n & 1][m] << '\n';

	return 0;
}
