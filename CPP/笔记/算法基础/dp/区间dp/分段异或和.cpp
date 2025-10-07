#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 507;
ll a[N], dp[N][N];//dp[i][j]��ʾ�Ե�i�ν�β������j�ε����Ž� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) dp[i][1] = dp[i - 1][1] ^ a[i];
	for(int i = 1; i <= n; i++)//i������ÿһ��Ϊ��β�Ŀ������ 
	{
		for(int j = 2; j <= i && j <= k; j++)//Ҫ����j�Σ�����1Ϊ��λ�����i�Σ����Ҳ���Ҫ����Ŀ����k���� 
		{
			ll sum = a[i];//sum�洢��j�ε����� 
			for(int t = i - 1; t >= j - 1; t--)//t��i-1��ʼ��ͬʱҪȷ���ܻ���j-1�Σ�t���ܱ�j-1��С 
			{
				dp[i][j] = max(dp[i][j], dp[t][j - 1] + sum);
				sum ^= a[t];
			}
		}
	}
	
	cout << dp[n][k];//��n��β������k�� 
	
	return 0;
}

