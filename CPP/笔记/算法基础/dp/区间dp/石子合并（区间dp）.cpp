#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 307;
const int inf = 2e9;
int a[N], dp[N][N], prefix[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];
	
	// ��̬�滮���		//ע�������len��ָ�м����㣬������һ������[1,1]�����ǳ���Ϊ1.[1,2]���ǳ���Ϊ2
	for(int len = 2; len <= n; len++) // �������п��ܵ����䳤�ȣ���2��ʼֱ��n
	{
		for(int i = 1, j = i + len - 1; j <= n; i++, j++) // �������п��ܵ����i���յ�j���������䳤��Ϊlen
		{
            // ��ʼ����ǰ�����dpֵΪ�����
			dp[i][j] = inf;
            
            // ����������[i, j]�ڵ�ÿһ��λ��k���зָ����ϲ����۲�ȡ��Сֵ
			for(int k = i; k < j; k++)
			{
                // ����dp[i][j]Ϊ�������[i, k]���ұ�����[k+1, j]�ϲ�����С���ۼ��Ϻϲ����������䱾��Ĵ��ۣ�����������ĺͣ�
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefix[j] - prefix[i - 1]);
			}
		}
	}

    // ������մ𰸣���������Ԫ�غϲ���һ��ʯ�Ӷ��������С����
	cout << dp[1][n];

	return 0;
}

//3
//3 5 4
//
//20
