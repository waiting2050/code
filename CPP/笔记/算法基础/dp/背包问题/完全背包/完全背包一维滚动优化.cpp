#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ���峣����N����Ʒ���������ֵ��һЩ������M�Ǳ������������ֵ��һЩ����
const int N = 507, M = 1e5 + 7;

// w����洢ÿ����Ʒ�����������������v����洢ÿ����Ʒ�ļ�ֵ
int w[N], v[N];

// dp�������ڶ�̬�滮��dp[i][j]��ʾǰi����Ʒ������Ϊjʱ������ֵ
ll dp[M];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> m >> n;
	
	for(int i = 1; i <= n; i++) 
		cin >> w[i] >> v[i]; // ע�������w��v�Ķ�������Ŀ�����෴��Ӧ����w[i]Ϊ������v[i]Ϊ��ֵ

	// ˼��� 01 ����һģһ�������˴����ܷ���ѭ����������ѭ������Ϊ dp[i][j]
 	//ʹ�õĶ���ͬ������ݣ��������ȡ����ȷ���ݣ�����Ļ���ȡ������һ�� dp �����ݡ�
	for(int i = 1; i <= n; i++) // ����ÿ����Ʒ
		for(int j = v[i]; j <= m; j++) // ����ÿ�ֿ��ܵ�������
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

	cout << dp[m] << '\n';

	return 0;
}
