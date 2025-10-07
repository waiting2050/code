#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 507;
int a[N][N], dp[N][N];//dp[i][j]��ʾ��[i,j]���ж����߶� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m, q; cin >> n >> m >> q;
	
	for(int i = 1; i <= m; i++)
	{
		int l, r; cin >> l >> r;
		a[l][r]++;
	}
	
	for(int len = 1; len <= n; len++)
		for(int i = 1, j = i + len - 1; j <= n; j++, i++)
			//�Ӵ���������С��С���䣨���ϱ��������������ڲ��ģ���ͬʱ��ȥ�ظ����֣����ϸպ���i,jΪ���Ҷ˵�� 
			dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + a[i][j];
	
	while(q--)
	{
		int x, y; cin >> x >> y;
		cout << dp[x][y] << '\n';
	}
	
	return 0;
}

